#include <std.h>
#include <new_exp_table.h>
#include <daemons.h>

inherit "/std/church.c";

//Race               Str    Dex     Con     Int     Wis     Cha
#define RACE_MINZ ([\
"aasimar"      :({   3,     3,      3,      3,      3,      3,   }),\
"beastman"     :({   6,     6,      6,      3,      3,      3,   }),\
"bugbear"      :({   8,     8,      8,      3,      3,      3,   }),\
"drow"         :({   8,     12,     4,      10,     8,      8,   }),\
"dwarf"        :({   8,     3,      12,     3,      3,      3,   }),\
"elf"          :({   3,     7,      6,      8,      3,      8,   }),\
"firbolg"      :({   14,    8,      12,     8,      8,      3,   }),\
"air genasi"   :({   3,     3,      3,      3,      3,      3,   }),\
"earth genasi" :({   3,     3,      3,      3,      3,      3,   }),\
"fire genasi"  :({   3,     3,      3,      3,      3,      3,   }),\
"water genasi" :({   3,     3,      3,      3,      3,      3,   }),\
"gnoll"        :({   6,     5,      5,      3,      3,      3,   }),\
"gnome"        :({   6,     3,      8,      7,      3,      3,   }),\
"goblin"       :({   4,     4,      5,      3,      3,      3,   }),\
"half-drow"    :({   3,     8,      6,      8,      3,      5,   }),\
"half-elf"     :({   3,     6,      6,      4,      3,      3,   }),\
"half-ogre"    :({   14,    3,      14,     3,      2,      2,   }),\
"half-orc"     :({   6,     3,      13,     3,      3,      3,   }),\
"halfling"     :({   6,     8,      9,      6,      3,      3,   }),\
"hobgoblin"    :({   6,     6,      5,      3,      3,      3,   }),\
"human"        :({   3,     3,      3,      3,      3,      3,   }),\
"kobold"       :({   3,     4,      4,      3,      3,      3,   }),\
"ogre"         :({   16,    2,      14,     2,      2,      2,   }),\
"ogre-mage"    :({   12,    7,      8,      8,      3,      2,   }),\
"orc"          :({   6,     3,      8,      3,      3,      3,   }),\
"tiefling"     :({   3,     3,      3,      3,      3,      3,   }),\
"voadkyn"      :({   11,    13,     8,      11,     3,      3,   }),\
"wemic"        :({   11,    6,      11,     3,      3,      3,   }),\
])

//Race               Str    Dex     Con     Int     Wis     Cha
#define RACE_MAXEZ ([\
"aasimar"      :({   18,    17,     18,     17,     19,     19,  }),\
"beastman"     :({   18,    19,     16,     18,     18,     17,  }),\
"bugbear"      :({   19,    17,     18,     16,     18,     14,  }),\
"drow"         :({   18,    20,     16,     19,     18,     16,  }),\
"dwarf"        :({   18,    17,     19,     18,     18,     16,  }),\
"elf"          :({   18,    19,     17,     18,     18,     18,  }),\
"firbolg"      :({   20,    15,     18,     18,     18,     14,  }),\
"air genasi"   :({   18,    19,     18,     19,     17,     17,  }),\
"earth genasi" :({   19,    18,     19,     17,     18,     17,  }),\
"fire genasi"  :({   18,    18,     18,     19,     18,     17,  }),\
"water genasi" :({   18,    18,     19,     18,     18,     17,  }),\
"gnoll"        :({   19,    18,     18,     14,     16,     14,  }),\
"gnome"        :({   18,    18,     18,     19,     17,     18,  }),\
"goblin"       :({   15,    17,     16,     18,     18,     12,  }),\
"half-drow"    :({   18,    19,     17,     18,     18,     16,  }),\
"half-elf"     :({   18,    18,     18,     18,     18,     18,  }),\
"half-ogre"    :({   19,    12,     19,     12,     12,     8,   }),\
"half-orc"     :({   19,    17,     19,     17,     17,     12,  }),\
"halfling"     :({   17,    19,     18,     18,     17,     18,  }),\
"hobgoblin"    :({   18,    18,     18,     18,     18,     14,  }),\
"human"        :({   18,    18,     18,     18,     18,     18,  }),\
"kobold"       :({   16,    18,     15,     17,     18,     14,  }),\
"ogre"         :({   20,     8,     20,     8,      9,      8,   }),\
"ogre-mage"    :({   19,    18,     14,     17,     16,     14,  }),\
"orc"          :({   19,    17,     18,     16,     16,     12,  }),\
"tiefling"     :({   18,    19,     18,     19,     18,     16,  }),\
"voadkyn"      :({   19,    20,     16,     17,     16,     18,  }),\
"wemic"        :({   19,    17,     18,     18,     18,     18,  }),\
])

void convert_me(object ob,mapping info);

void create()
{
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_property("training",1);
    set_property("church",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no teleport",1);
    set_property("no starve",1);
    set_property("conversion room",1);
  
    set_name("beyond the haze");
    set_short("%^BOLD%^%^BLUE%^Beyond the Haze%^RESET%^");
  
    set_long("%^BOLD%^%^BLUE%^Beyond the Haze%^RESET%^\n"+
        "%^BOLD%^%^CYAN%^You settle into reality once more, "+
        "but find yourself changed.  You realize that you can "+
        "reshape yourself into anything.\n\n"+
        "%^YELLOW%^Welcome SGers to the newly revised Character "+
        "Build.  For those who were already in game at the "+
        "change over, this is your chance to recreate your "+
        "character.  You will notice by typing %^CYAN%^<score>"+
        "%^YELLOW%^ that you are now level 1.  You will also see "+
        "that you have a large pile of negative experience.  "+
        "(Adjusted to balance with the revised, universal XP "+
        "tables.) We have also reversed your levels so that "+
        "you can create your character using your current XP "+
        "earned, including taking advantage of the new %^WHITE%^"+
        "feats%^YELLOW%^, %^RED%^stats %^YELLOW%^and %^GREEN%^"+
        "multiclass system%^YELLOW%^, which allows for several "+
        "new multiclass options.  For more help, please read "+
        "the following help files:\n\n"+
        "%^MAGENTA%^                      <help conversion>\n"+
        "%^GREEN%^         <help advance>  %^WHITE%^<help feats>  "+
        "%^RED%^<help stats>%^RESET%^\n\n"+
        "%^YELLOW%^You can also use the %^CYAN%^<thought>%^YELLOW%^ "+
        "command if you need help.  However, please keep in mind "+
        "that it might take us a little bit to get to you. So "+
        "please be patient.%^RESET%^\n\n%^B_BLUE%^%^WHITE%^"+
        "There are 4 levers here that you can look at.\n\n%^RESET%^"
        "You may select cleric domains in this room and you may type "
        "help advance to select mage schools, psion disciplines and "
        "fighter styles.%^RESET%^");

    set_items(([ ({"lever","levers"}) : "There are 4 levers here, <look lever 1> <look lever 2> etc",
        ({"lever one","lever 1"})     : "If you are a mage or bard, pulling lever 1 will give you a spellbook.",
        ({"lever two","lever 2"})     : "If you are a psion, pulling lever 2 will give you a psicrystal",
        ({"lever three","lever 3"})   : "If you are a cleric,paladin,antipaladin or ranger, pulling level 3 "
                                        "will give you a holy symbol.",
        ({"lever four","lever 4"})    : "Pulling lever 4 will allow you to adjust your stats around BEFORE you "
                                        "add any stat points to your character.  This should be used to make your "
                                        "new stats match the class choices that you plan to make.",
    ]));

    set_smell("default","\nThere is nothing within the haze "+
        "to smell.");
    set_listen("default","You can hear nothing within the "+
        "haze.");

    set_exits((["out":"/d/shadowgate/conversion/stats1"]));

    set_pre_exit_functions(({"out"}),({"GoThroughDoor"}));
    call_out("heal_people",5);
}

int GoThroughDoor()
{
    if(!objectp(TP)) { return 0; }
    if(avatarp(TP)) { return 1; }
    if(!TP->query_property("finished")) 
    {
        tell_object(TP,"Make sure your character is finished before you leave.  Type "
            "<finish> if you are done setting your feats and your stats.");
        return 0; 
    }
    return 1;
}

void confirm_finish(string str,object ob)
{
    if(!objectp(ob)) { return; }
    if(str != "yes") 
    {
        tell_object(ob,"Aborting...");
        return;
    }
    tell_object(ob,"Finishing...  Your character can now leave the room "
        "and adjust its stats in the next.");
    ob->set_property("finished",1);
    return;
}

void finish_me(string str)
{
    if(!objectp(TP)) { return; }
    if(!TP->query("new_class_type")) { return; }
    if(TP->query_property("finished"))
    {
        tell_object(TP,"You are already finished with your character.");
        return;
    }
    new("/d/avatars/lurue/newsgmemento.c")->move(TP);
    tell_object(TP,"%^RED%^  Are you sure that you are finished?  The exp cost "
        "for feats and stats will only increase as your character gains in levels.");
    tell_object(TP,"Enter <yes> to confirm that you are finished, enter anything "
        "else to abort.");
    input_to("confirm_finish",TP);
    return;
}

void single_class_me(string str,mapping info)
{
    mapping levels;
    string *classes,myclass,*level_keys;
    int i,num;

    if(!mapp(info)) { return; }
    if(!objectp(info["player"])) { return; }

    str = lower_case(str);

    classes = info["classes"];

    if(member_array(str,classes) == -1)
    {
        tell_object(TP,"You must enter one of your classes: "+implode(classes," ")+". NOTE: "
            "You will be given a chance to adjust your stats before leaving this room.");
        input_to("single_class_me",info);
        return;
    }
    myclass = str;
    levels = (mapping)info["player"]->query_levels();
    level_keys = keys(levels);
    info["player"]->force_me("pose "+myclass+"");

    for(i=0;i<sizeof(level_keys);i++)
    {
        if(level_keys[i] == myclass) { continue; }
        info["player"]->set_mlevel(level_keys[i],0);
        info["player"]->set_guild_level(level_keys[i],0);
        info["player"]->remove_class(level_keys[i]);
    }

    info["player"]->init_spellcaster();

    convert_me(info["player"],info);
    return;
}

void convert_me(object ob,mapping info)
{
    string *classes,myclass;
    int level,exp;

    if(!objectp(ob)) { return; }
    if(!interactive(ob)) { return; }
    if(ob->query("new_class_type")) { return; }

    TP->set_property("converting",1);

    classes = (string *)ob->query_classes();

    if(!info["level"])
    {
        level   = ob->query_highest_level();
        info["level"]   = level;
    }
    if(!info["exp"] && level < 50)
    {
        exp     = EXP_NEEDED[level+1];
        info["exp"]     = exp;
    }
	else 
	{
		exp = 1;
		info["exp"] = 1;
	}

    info["player"]  = ob;
    info["classes"] = classes;

    if(sizeof(classes) > 1)
    {
        tell_object(ob,"%^RED%^You must pick one class that you will start with, "
            "you will be given an opportunity to multiclass later at level 10, 20, "
            "and 30.  Your total character level will now be calculated by adding "
            "your class levels together.  A level 10/10 psion/mage will be considered "
            "a level 20 character.\n\n %^MAGENTA%^NOTE:  You will be given a chance "
            "to adjust your stats before leaving this room.%^RESET%^");
        tell_object(ob,"Please enter which one of your classes that you would like "
            "to begin the game with: "+implode(classes," ")+".");
        input_to("single_class_me",info);
        return;
    }
    myclass = (string)ob->query_class();

    tell_object(ob,"%^BOLD%^Reducing level...");
   
    ob->set("new_class_type",1);
    ob->force_me("fixspells");
    ob->delete("active_class");
    ob->set_divine_domain(({}));
    ob->set_school(0);
    ob->set_discipline(0);
    ob->set_fighter_style(0);
    ob->resetLevelForExp(0);
    ob->set_mlevel(myclass,0);
    ob->set_guild_level(myclass,0);
    ob->set_advanced(0);
    ob->clear_feats();
    ob->set_max_hp(20);
    ob->set_hp(ob->query_max_hp());

    tell_object(ob,"%^BOLD%^Converting to new class format...");

    ob->add_exp(1);
    ADVANCE_D->advance(ob,myclass);
    ob->set("active_class",myclass);
    ob->add_exp(info["exp"]);
    ob->set_hp(ob->query_max_hp());
    ob->init_skills("none");
    "/cmds/mortal/_advance.c"->add_class_feats(ob,myclass);

    tell_object(ob,"%^BOLD%^Done.. ");

    tell_object(ob,"%^YELLOW%^Your character has been converted over to the new "
        "format.  Your level has been reset to 1 and you have been given experience "
        "points to equal what a character of your level would have on our new "
        "experience table.  See %^MAGENTA%^help stats%^YELLOW%^, %^MAGENTA%^help feats "
        "%^YELLOW%^and %^MAGENTA%^help advance.  %^YELLOW%^A lot of other changes "
        "have been made as well.  For a description of those changes see "
        "%^MAGENTA%^help conversion%^YELLOW%^.  Please read the help files carefully.");
    TP->remove_property("converting");
    return;
}    

int age_adjust(object ob,string stat,int num)
{
    string age_string;
    int *adjustments,index,mod;

    if(!objectp(ob)) { return 0; }

    age_string = (string)"/cmds/mortal/_stats.c"->get_age(ob,(int)ob->query_real_age());

    switch(age_string)
    {
    case "child":
        adjustments = ({ -1,  1, -1, -1, -1,  1 });
        break;
    case "average":
        adjustments = ({  0,  0,  0,  0,  0,  0 });
        break;
    case "middle":
        adjustments = ({ -1,  0, -1,  1,  1,  0 });
        break;
    case "old":
        adjustments = ({ -3, -2, -2,  1,  2,  0 });
        break;
    case "venerable":
        adjustments = ({ -4, -3, -3,  2,  3,  0 });
    default: return 0;
    }

    switch(stat)
    {
    case "strength":     index = 0; break;
    case "dexterity":    index = 1; break;
    case "constitution": index = 2; break;
    case "intelligence": index = 3; break;
    case "wisdom":       index = 4; break;
    case "charisma":     index = 5; break;
    }

    mod = adjustments[index];
    return num += mod;
}

int race_min(string race,string stat,int num,object ob)
{
    int index,min,*stats;
    if(member_array(race,keys(RACE_MINZ)) == -1)
    {
        return notify_fail("Your race isn't listed, contact a wiz.");
    }
    switch(stat)
    {
    case "strength":     index = 0; break;
    case "dexterity":    index = 1; break;
    case "constitution": index = 2; break;
    case "intelligence": index = 3; break;
    case "wisdom":       index = 4; break;
    case "charisma":     index = 5; break;
    }

    stats = RACE_MINZ[race];
    min   = stats[index];
//    min   = age_adjust(ob,stat,min);

    if(num < min) { return 0; }
    return 1;
}

int race_max(string race,string stat,int num,object ob)
{
    int index,max,*stats;
    if(member_array(race,keys(RACE_MAXEZ)) == -1)
    {
        return notify_fail("Your race isn't listed, contact a wiz.");
    }
    switch(stat)
    {
    case "strength":     index = 0; break;
    case "dexterity":    index = 1; break;
    case "constitution": index = 2; break;
    case "intelligence": index = 3; break;
    case "wisdom":       index = 4; break;
    case "charisma":     index = 5; break;
    }

    stats = RACE_MAXEZ[race];
    max   = stats[index];
//    max   = age_adjust(ob,stat,max);

    if(num > max) { return 0; }
    return 1;
}

int class_min(string myclass,string stat,int num)
{
    mapping stats_required;
    string file;

    file = "/std/class/"+myclass+".c";
    if(!file_exists(file))
    {
        return notify_fail("Your class isn't listed, contact a wiz.");
    }
    stats_required = (mapping)file->stat_requirements();
    if(!sizeof(keys(stats_required))) { return 1; }
    if(member_array(stat,keys(stats_required)) == -1) { return 1; }
    if(stats_required[stat] > num) { return 0; }
    return 1;
}

int allowed_mod(mapping stats)
{
    string *valid_subraces=({"aasimar","earth genasi","air genasi","fire genasi","water genasi","tiefling"});
    mapping stat_add,stat_subtract;
    string add,subtract,race,myclass,subrace,file;
    int new_add,new_subtract;
    object ob;
    
    if(!mapp(stats))              { return 0; }
    if(!objectp(stats["player"])) { return 0; }
    if(!mapp(stats["add"]))       { return 0; }
    if(!mapp(stats["subtract"]))  { return 0; }

    ob            = stats["player"];
    stat_add      = stats["add"];
    stat_subtract = stats["subtract"];
    add           = implode(keys(stat_add)," ");
    subtract      = implode(keys(stat_subtract)," ");
    new_add       = stat_add[add];
    new_subtract  = stat_subtract[subtract];
    race          = (string)ob->query_race();
    myclass         = (string)ob->query_class();
    file          = "/std/class/"+myclass+".c";

    if(ob->query("subrace"))
    {
        subrace = lower_case((string)ob->query("subrace"));
        if(member_array(subrace,valid_subraces) != -1)
        {
            race = subrace;
        }
    }

    if(!race_max(race,add,new_add,ob))
    {
        tell_object(ob,"%^RED%^"+new_add+" "+add+" would excede the racial maximum.  This "
            "editor does not allow you to pass the racial maximum.");
        return 0;
    }
    if(!race_min(race,subtract,new_subtract,ob))
    {
        tell_object(ob,"%^RED%^"+new_subtract+" "+subtract+" would be below the race "
            "minimum.  You can't have a stat below the race minimum.");
        return 0;
    }
    if(!class_min(myclass,subtract,new_subtract))
    {
        tell_object(ob,"%^RED%^"+new_subtract+" "+subtract+" would be below the "
            "minimum allowed for "+myclass+".%^RESET%^");
        return 0;
    }
    return 1;
}

string stat_string(string str)
{
    switch(str)
    {
    case "str": return "strength";
    case "dex": return "dexterity";
    case "con": return "constitution";
    case "int": return "intelligence";
    case "wis": return "wisdom";
    case "cha": return "charisma";
    default:    return str;
    }
    return str;
}

void do_stat_mods(string str,object ob)
{
    mapping new_stats;
    string *stats=({"str","strength","dex","dexterity","con","constitution","int","intelligence","wis","wisdom","cha","charisma"});
    string *info,add,subtract,new_add,new_subtract;
    int num;
    if(!objectp(ob)) { return; }

    if(!str || str == "" || str == " ")
    {
        ob->force_me("stats");
        do_stat_mods("start",ob);
        return;
    }

    info = explode(lower_case(str)," ");
    if(!sizeof(info)) { return; }

    switch(info[0])
    {
    case "start":
        tell_object(ob,"%^BOLD%^You are allowed to adjust your stat points around to fit "
            "the character concept that you are trying to build.  You may move around your "
            "stats as much as you want until you are finished and then you must type either "
            "<done> or <finish> to exit the editor.  Note:  For the purpose of this editor, "
            "you are not allowed to excede the racial max and min amounts adjusted for age and "
            "you will also not be allowed to lower a stat below the minimum required for your "
            "class.");
        tell_object(ob,"%^YELLOW%^Syntax: subtract 3 from str and add to dex");
        ob->force_me("stats");
        input_to("do_stat_mods",ob);
        break;

    case "subtract":
        if(sizeof(info) != 8)
        {
            tell_object(ob,"%^YELLOW%^Syntax: subtract 3 from str and add to dex");
            ob->force_me("stats");
            input_to("do_stat_mods",ob);
            break;
        }
        if(!intp(to_int(info[1])) || member_array(info[3],stats) == -1 || member_array(info[7],stats) == -1 || info[3] == info[7] || info[2] != "from" || info[4] != "and" || info[5] != "add" || info[6] != "to")
        {
            tell_object(ob,"%^YELLOW%^Syntax: subtract 3 from str and add to dex");
            ob->force_me("stats");
            input_to("do_stat_mods",ob);
            break;
        }
        num          = to_int(info[1]);
        add          = info[7];
        add          = stat_string(add);
        subtract     = info[3];
        subtract     = stat_string(subtract);
        new_add      = ((int)ob->query_base_stats(add) + num);
        new_subtract = ((int)ob->query_base_stats(subtract) - num);
        //tell_object(find_player("saide"), "num = "+num+" new_add = "+new_add+" ("+add+") and new_subtract = "+new_subtract + " ("+subtract+")");
        
        new_stats = ([ "player" : ob, "add" : ([ add : new_add ]), "subtract" : ([ subtract : new_subtract]), ]);
        
        if(!allowed_mod(new_stats))
        {
            ob->force_me("stats");
            input_to("do_stat_mods",ob);
            break;
        }

        ob->set_stats(add,new_add);
        ob->set_stats(subtract,new_subtract);

        tell_object(ob,"%^YELLOW%^Subtracting %^BLUE%^"+num+"%^YELLOW%^ from "+subtract+" and "
            "adding %^BLUE%^"+num+"%^YELLOW%^ to "+add+".");
        ob->force_me("stats");
        input_to("do_stat_mods",ob);
        break;

    case "done":
    case "finish":

        tell_object(ob,"Finishing...");
        ob->force_me("stats");
        break;

    default:
        tell_object(ob,"%^BOLD%^You are allowed to adjust your stat points around to fit "
            "the character concept that you are trying to build.  You may move around your "
            "stats as much as you want until you are finished and then you must type either "
            "<done> or <finish> to exit the editor.  Note:  For the purpose of this editor, "
            "you are not allowed to excede the racial max and min amounts adjusted for age and "
            "you will also not be allowed to lower a stat below the minimum required for your "
            "class.");
        tell_object(ob,"%^YELLOW%^Syntax: subtract 3 from str and add to dex");
        ob->force_me("stats");
        input_to("do_stat_mods",ob);
        break;
    }
    return 1;
} 

int pull_lever(string str)
{
    string *info;
    if(!stringp(str) || str == "" || str == " ") { return 0; }

    info = explode(str," ");
    if(sizeof(info) != 2) { return 0; }
    if(info[0] != "lever") { return 0; }

    switch(info[1])
    {
    case "1":
    case "one":

        if(!avatarp(TP) && !TP->is_class("mage") && !TP->is_class("bard"))
        {
            tell_object(TP,"You are not a mage or a bard and you do not need a spellbook.");
            return 1;
        }
        tell_object(TP,"Here is your spellbook");
        new("/d/magic/spellbook.c")->move(TP);
        return 1;

    case "2":
    case "two":

        if(!avatarp(TP) && !TP->is_class("psion"))
        {
            tell_object(TP,"You are not a psion and do not need a psicrystal");
            return 1;
        }
        tell_object(TP,"Here is your psicrystal");
        new("/d/magic/psicrystal.c")->move(TP);
        return 1;

    case "3":
    case "three":

        if(!avatarp(TP) && !TP->is_class("ranger") && !TP->is_class("paladin") && !TP->is_class("antipaladin") && !TP->is_class("cleric"))
        {
            tell_object(TP,"You are not a cleric, paladin, antipaladin, or ranger and you do not need a holy symbol.");
            return 1;
        }
        tell_object(TP,"Here is your holy symbol");
        new("/d/magic/symbols/holy_symbol.c")->move(TP);
        return 1;

    case "4":
    case "four":

        if(TP->query("stat_points_gained"))
        {
            tell_object(TP,"You have already added stat points and you may no longer adjust your stats");
            return 1;
        }
        do_stat_mods("start",TP);
        return 1;
    }
    return 1;
}

void init()
{
    ::init();
    add_action("finish_me","finish");
    add_action("pull_lever","pull");

    if(!objectp(TP)) { return; }
    if(avatarp(TP)) { return; }
    if(TP->query("new_class_type")) { return; }

    convert_me(TP,([]));
    return;
}

void heal_people()
{
    object *living;
    int i;

    if(!objectp(TO)) { return; }
    if(!present("spellbert")) { new("/d/shadowgate/conversion/spellbert.c")->move(TO); }

    living = all_living(TO);
    living = filter_array(living,"is_non_immortal_player",FILTERS_D);
    if(!sizeof(living))
    {
        call_out("heal_people",5);
        return;
    }
    for(i=0;i<sizeof(living);i++)
    {
        if(!objectp(living[i])) { continue; }
        living[i]->set_hp((int)living[i]->query_max_hp());
    }
    call_out("heal_people",5);
    return;
}




