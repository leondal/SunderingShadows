#include <std.h>
#include <daemons.h>
#include <skills.h>
#include <new_exp_table.h>
inherit DAEMON;

// disguise moved from valid skills til it is returned later with the disguise command. N, 1/14.
void display_skills(object asking, object ob);

int calculate_skill_cost(object ob,int points){
    int level,exp;
    if(!objectp(ob)) return 0;
    if(!intp(points)) return 0;

    level = ob->query_highest_level();
    if(level == 1) return 0;
    if(!avatarp(ob)) {
      exp = ((EXP_NEEDED[level + 1])*points)/100; // 1% exp for every point moved; cheap for single points but can be expensive in bulk.
      return exp;
    }
    return 0;
}

int confirm_remove(string str,object ob,string myskill,int points) {
    int price, newtotal;

    if(!objectp(ob)) return 0;
    if(!stringp(myskill)) return 0;
    if(!intp(points)) return 0;
    if(str != "yes") {
       tell_object(ob,"Skill removal cancelled.");
       return 1;
    }
    newtotal = (int)ob->query_base_skill(myskill) - points;
    if(newtotal < 0) return notify_fail("You haven't applied that many points to the skill!\n");

    price = calculate_skill_cost(ob,points);

    if(!avatarp(ob))
    {
        if((int)"/daemon/config_d.c"->check_config("character improvement") == 0)
        {
            ob->add_exp(price * -1);
            ob->resetLevelForExp(0);
            ob->remove_XP_tax("improvement");
            tell_object(ob,"%^BOLD%^%^WHITE%^Subtracting "+price+" experience points.");
        }
        else if((int)"/daemon/config_d.c"->check_config("character improvement") == 1)
        {
            if((int)ob->set_XP_tax(price, 0, "improvement") == -1)
            {
                tell_object(ob, "Currently your character improvement tax is above the maximum allowed. "+
                "You must first reduce it before you can remove skill points.");
                return 1;
            }
            tell_object(ob,"%^BOLD%^%^WHITE%^Adding a character improvement tax of "+price+". This tax will reduce "+
            "all future experience gained by %^RED%^50%%^WHITE%^ until it is repaid.%^RESET%^");
        }
    }

    ob->set_skill(myskill,newtotal);
    tell_object(ob,"%^BOLD%^%^WHITE%^You have reduced your "+myskill+" skill by "+points+" points.%^RESET%^");
    return 1;
}

int cmd_skills(string str)
{
    int points, newtotal, checkflag = 0;
    string myskill;
    object ob;

    if(!stringp(str)) {
      display_skills(TP,TP);
      return 1;
    }
    str = lower_case(str);
    if(avatarp(TP) && objectp(ob=find_player(str))) {
      display_skills(TP,ob);
      return 1;
    }
    if(!TP->query("new_class_type")) return 1;
    if(sscanf(str,"add %d to %s",points,myskill) == 2)
    {
      if(member_array(myskill,VALIDSKILLS) == -1) return notify_fail(""+capitalize(myskill)+" is not a valid skill.\n");
      if(points < 1) return notify_fail("You can only add a positive number of points to a skill.\n");
      newtotal = (int)TP->query_base_skill(myskill) + points;
      if(member_array(myskill,CORE_SKILLS) != -1) { // for core skills...
        if(((int)TP->query_used_skills()+points) > (int)TP->query_max_skills())
          return notify_fail("That will assign more than your maximum core skills for this level.\n");
        else checkflag++;
      }
      if(member_array(myskill,CRAFT_SKILLS) != -1) { // for craft skills...
        if(((int)TP->query_used_craft_skills()+points) > (int)TP->query_max_craft_skills())
          return notify_fail("That will assign more than your maximum craft skills for this level.\n");
        else checkflag++;
      }
      if(!checkflag)
        return notify_fail("Your have chosen a skill that does not register as core or craft type. Please contact a wiz and provide this error message.\n");
      if(checkflag > 1)
        return notify_fail("Your have chosen a skill that registers as both core and craft type. Please contact a wiz and provide this error message.\n");
      if(newtotal > ((int)TP->query_level()/2))
        return notify_fail("Adding "+points+" points to your "+myskill+" skill will surpass your maximum allowed.\n");
      if(TP->query("negative level"))
      {
        tell_object(TP, "You have a negative level and must have it removed before "+
        "you can add any skills!");
        return 1;
      }
      if(intp(USER_D->get_scaled_level(TP)))
      {
        tell_object(TP, "You have scaled your level down and must revert it back to "+
        "normal before you can add any skills!");
        return 1;
      }
      TP->set_skill(myskill,newtotal);
      tell_object(TP,"%^BOLD%^%^WHITE%^You have increased your "+myskill+" skill by "+points+" points.%^RESET%^");
      return 1;
    }
    if(sscanf(str,"remove %d from %s",points,myskill) == 2)
    {
      if(member_array(myskill,VALIDSKILLS) == -1) return notify_fail(""+capitalize(myskill)+" is not a valid skill.\n");
      if(points < 1) return notify_fail("You can only remove a positive number of points to a skill.\n");
      newtotal = (int)TP->query_base_skill(myskill) - points;
      if(newtotal < 0) return notify_fail("You haven't applied that many points to the skill!\n");
      if(TP->query("negative level"))
      {
        tell_object(TP, "You have a negative level and must have it removed before "+
        "you can remove any skills!");
        return 1;
      }
      if(intp("/daemon/user_d.c"->get_scaled_level(TP)))
      {
        tell_object(TP, "You have scaled your level down and must revert it back to "+
        "normal before you can remove any skills!");
        return 1;
      }
      if((int)"/daemon/config_d.c"->check_config("character improvement") == 0)
      {
            tell_object(TP,"%^BOLD%^%^WHITE%^Are you sure you want to remove "+points+" from the "+myskill+" skill?  It will "
            "cost you %^YELLOW%^"+calculate_skill_cost(TP,points)+" %^WHITE%^exp.%^RESET%^");
      }
      else if((int)"/daemon/config_d.c"->check_config("character improvement") == 1)
      {
          tell_object(TP, "%^BOLD%^%^WHITE%^Are you sure you want to remove "+points+" from the "+myskill+" skill?  Doing so "+
          "will cause you to incur a character improvement tax of "+calculate_skill_cost(TP, points)+". This tax will "+
          "reduce all future gained experience by %^RED%^50%%^WHITE%^ until repaid.");
      }
      tell_object(TP,"%^BOLD%^%^WHITE%^Enter <yes> to remove the points, or anything else to abort.");
      input_to("confirm_remove",TP,myskill,points);
      return 1;
    }
    return notify_fail("See <help skills> for syntax.\n");
}

//recoding the following to use the VALIDSKILLS array and to display
//class skills in BOLD WHITE - non class skills in the original BOLD GREEN
//Saide, January 2017
void display_skills(object asking, object ob)
{
    int x;
    string SKILL_COL, LCOLOR, BCOLOR, thisSkill, msg, *myclasses, *myclassskills, mydisc, file;
    // hard reset on points allocated to disguise. please remove this when it is returned to the game. N, 1/14.
    if((int)ob->query_base_skill("disguise") > 0) ob->set_skill("disguise",0);

    tell_object(asking,"%^BOLD%^%^MAGENTA%^Core skills for %^WHITE%^"+capitalize(ob->query_name())+" %^CYAN%^("
+ob->query_used_skills()+"/"+ob->query_max_skills()+")%^BOLD%^%^MAGENTA%^:%^RESET%^\n");
    tell_object(asking,""+arrange_string("%^BOLD%^%^GREEN%^Skill",21)+
    arrange_string("%^CYAN%^Rank%^BLUE%^(base)", 14)+
    arrange_string("%^GREEN%^Skill",21)+
    arrange_string("%^CYAN%^Rank%^BLUE%^(base)", 14)+"\n");

    LCOLOR = "%^BOLD%^%^CYAN%^";
    BCOLOR = "%^BLUE%^";

    myclasses = ob->query_classes();
    myclassskills = ({});

    for(x = 0;x<sizeof(myclasses);x++)
    {
        file = DIR_CLASSES+"/"+myclasses[x]+".c";
        if(file_exists(file))
        {
            if(myclasses[x] == "psion")
            {
                mydisc = ob->query_discipline();
                myclassskills += (string *)file->discipline_skills(mydisc);
            }
            else if(myclasses[x] == "monk")
            {
                mydisc = ob->query("monk way");
                myclassskills += (string *)file->way_skills(mydisc);
            }
            else if(myclasses[x] == "oracle")
            {
                mydisc = ob->query_mystery();
                myclassskills += (string *)file->mystery_skills(mydisc);
            }
            else  myclassskills += (string *)file->class_skills(ob);
        }
        continue;
    }
    if(FEATS_D->usable_feat(ob,"skill focus"))
    {
        myclassskills += ({((string)ob->query("skill_focus"))});
    }
    myclassskills = distinct_array(myclassskills);

    for(x = 0;x < sizeof(CORE_SKILLS);x++)
    {
        thisSkill = CORE_SKILLS[x];
        if(member_array(thisSkill, myclassskills) != -1) SKILL_COL = "%^BOLD%^%^WHITE%^";
        else SKILL_COL = "%^BOLD%^%^GREEN%^";
        msg = ""+arrange_string(SKILL_COL+capitalize(thisSkill),22)+
        arrange_string(LCOLOR+(int)ob->query_skill(thisSkill)+BCOLOR+"("+
        (int)ob->query_base_skill(thisSkill)+")", 13);
        if((x+1) < (sizeof(CORE_SKILLS)))
        {
            x++;
            thisSkill = CORE_SKILLS[x];
            if(member_array(thisSkill, myclassskills) != -1) SKILL_COL = "%^BOLD%^%^WHITE%^";
            else SKILL_COL = "%^BOLD%^%^GREEN%^";
            msg += arrange_string(SKILL_COL+capitalize(thisSkill),22)+
            arrange_string(LCOLOR+(int)ob->query_skill(thisSkill)+BCOLOR+"("+
            (int)ob->query_base_skill(thisSkill)+")", 13);
        }
        tell_object(asking, msg);
        continue;
    }

    tell_object(asking,"\n%^BOLD%^%^MAGENTA%^Craft skills for %^WHITE%^"+capitalize(ob->query_name())+" %^CYAN%^("
+ob->query_used_craft_skills()+"/"+ob->query_max_craft_skills()+")%^BOLD%^%^MAGENTA%^:%^RESET%^\n");
    tell_object(asking,""+arrange_string("%^BOLD%^%^GREEN%^Skill",21)+
    arrange_string("%^CYAN%^Rank%^BLUE%^(base)", 14)+
    arrange_string("%^GREEN%^Skill",21)+
    arrange_string("%^CYAN%^Rank%^BLUE%^(base)", 14)+"\n");

    for(x = 0;x < sizeof(CRAFT_SKILLS);x++)
    {
        thisSkill = CRAFT_SKILLS[x];
        msg = ""+arrange_string("%^BOLD%^%^GREEN%^"+capitalize(thisSkill),22)+
        arrange_string(LCOLOR+(int)ob->query_skill(thisSkill)+BCOLOR+"("+
        (int)ob->query_base_skill(thisSkill)+")", 13);
        if((x+1) < (sizeof(CRAFT_SKILLS)))
        {
            x++;
            thisSkill = CRAFT_SKILLS[x];
            msg += arrange_string("%^BOLD%^%^GREEN%^"+capitalize(thisSkill),22)+
            arrange_string(LCOLOR+(int)ob->query_skill(thisSkill)+BCOLOR+"("+
            (int)ob->query_base_skill(thisSkill)+")", 13);
        }
        tell_object(asking, msg);
        continue;
    }
    tell_object(asking,"");
    return;
}

int help(){

    write("
%^CYAN%^NAME%^RESET%^

skills - display and manage your skills

%^CYAN%^SYNOPSIS%^RESET%^

skills
skills add %^ORANGE%^%^ULINE%^NUMBER%^RESET%^ to %^ORANGE%^%^ULINE%^SKILL%^RESET%^
skills remove %^ORANGE%^%^ULINE%^NUMBER%^RESET%^ from %^ORANGE%^%^ULINE%^SKILL%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This command will list the skills available on the mud.  The number in brackets is your base, unmodified skill, which you allocate yourself with points. For core skills, you will receive 4 points per 2 levels to spend as you choose; thieves and bards will receive 6 points per 2 levels. For craft skills, you will receive 1 point per 2 levels regardless of class.

To add points to a skill use %^ORANGE%^<skills add %^ORANGE%^%^ULINE%^NUMBER%^RESET%^%^ORANGE%^ to %^ORANGE%^%^ULINE%^SKILL%^RESET%^%^ORANGE%^>%^RESET%^. You can only spend limited amount of free points based on your level and class.

To remove poins from a skill use %^ORANGE%^<skills remove %^ORANGE%^%^ULINE%^NUMBER%^RESET%^%^ORANGE%^ from %^ORANGE%^%^ULINE%^SKILL%^RESET%^%^ORANGE%^>%^RESET%^. This will incur a character improvement tax based on your level.

Your rank in a skill, outside the brackets, is your total modified skill, which you use in your checks. It includes bonuses from:
 * stats:  1 point per 2 past 10, in the appropriate stat
 * levels: 1 point per 2 levels for class skills, 1 point per 5 for non-class
 * Other, such as items, spells and effects.

%^CYAN%^SEE ALSO%^RESET%^

individual skill help files, score, stats, feats, spells, recall, hide_in_shadows
");
   return 1;
}
