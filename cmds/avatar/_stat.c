#include <std.h>
#include <daemons.h>
#include <str_fmt.h>
inherit DAEMON;

void show_quests();
void money_display();
void stats_display();

mapping vars=([]);

int query_stance_bonus(object target)
{
	if (interactive(target)) { return target->query_defensive_bonus(); }
	return 0;
}

int cmd_stat(string str)
{
    string name, title, *classes, race, married, guild, cl, diety, sphere, domain;
    int *levels, hp, max_hp, mp, max_mp, sp, max_sp, exp, i, lev, height, weight;
    int ac, dexac, stanceac, at_bon, dam_bon;
    string posxxx;
    object ob;
    levels = allocate(4);
    classes = ({});
    if (!str) {
        notify_fail("stat <living>\n");
        return 0;
    }
    str = lower_case(str);
// changed the order to check current environment first since usually we're
// wanting to check something we're testing or is in the same room *Styx* 1/17/03
   if (!(ob = present(str, ETP)))
        if (!(ob = to_object(str)))
            if (!(ob = find_object(str))) {
                notify_fail("Failed to find: "+str+".\n");
                return 0;
            }
    if (!living(ob)) {
        notify_fail("That is not a living object.\n");
        return 0;
    }

    if(ob->is_player())
    {
        posxxx = lower_case((string)TP->query_position());
        if(posxxx == "builder" || posxxx == "apprentice")
        {
            tell_object(TP,"You cannot use this command as a builder or apprentice.");
            return 1;
        }
    }
    if(wizardp(ob) && !wizardp(TP))
        return notify_fail("Failed to find: "+str+".\n");
    if (wizardp(ob) && wizardp(TP))
        if (ob->query_level() > TP->query_level())
            return notify_fail("Failed to find: "+str+".\n");
    title = (string)ob->query_short();
    classes = (string *)ob->query_classes();
    race = (string)ob->query_race();
    if(ob->query_property("new_exp_amount")) { exp = (int)ob->query_property("new_exp_amount"); }
    else { exp = (int)ob->query_exp(); }
    hp = (int)ob->query_hp();
    //ac = ob->query_ac();
    ac = BONUS_D->effective_ac(ob);
    at_bon = (int)ob->query_attack_bonus();
    dam_bon = (int)ob->query_damage_bonus();
    dexac = BONUS_D->ac_bonus(ob,ob);
    //dexac *= -1;

//  write("dexac bonus:"+identify(dexac));
    dexac = ac + dexac;
    //stanceac = query_stance_bonus(ob);
//  write("stanceac bonus:"+identify(stanceac));
    stanceac = dexac + stanceac;
    max_hp = (int)ob->query_max_hp();
    mp = (int)ob->query_mp();
    max_mp = (int)ob->query_max_mp();
    sp = (int)ob->query_sp();
    max_sp = (int)ob->query_max_sp();
    married = (string)ob->query_married();
    guild = (string)ob->query_guild_string();
    diety = (string)ob->query_diety();
    sphere = (string)ob->query_sphere();
    domain = implode(ob->query_divine_domain(), ", ");

    weight = (int)ob->query_player_weight();
    height = (int)ob->query_player_height();
    if (!married) married = "none";
    if (guild=="") guild = "none";
    if (!race) race = "undefined";
    if (!diety || diety == "pan") diety = "none";
    if (!sphere) sphere = "none";
    if (classes==({})) {
        cl = "none";
        lev = 0;
        printf("%s%s\n",
               arrange_string("Class: "+cl, 25),
               arrange_string("Level: "+lev, 25));
    } else {
        for (i=0;i<sizeof(classes);i++) {
            levels[i]=ob->query_class_level(classes[i]);
        }
        write(title +"  ("+base_name(ob)+")");
        for (i=0;i<sizeof(classes);i++) {
            printf("%s%s\n",
                   arrange_string("Class: "+classes[i], 25),
                   arrange_string("Level: "+levels[i], 25));
        }
    }
    printf("%s%s%s\n",
           arrange_string(hp+"/"+max_hp+" Hit Points", 25),
           arrange_string("Experience: "+exp, 25),
           arrange_string("AC:+=Dex:+=Stance: "+ac+":"+dexac+":"+stanceac,35));
    printf("%s%s%s\n",
           arrange_string("Race: "+race,25),
           arrange_string("Alignment: "+ob->query_alignment() + "(" + ob->query_true_align() + ")",25),
           arrange_string("Sex: "+(string)ob->query_gender(), 25) );
     printf("%s%s%s\n",
           arrange_string("Height: "+height,25),
           arrange_string("Weight: "+weight,25),
           arrange_string("Body Type: "+ob->query_body_type(),25));
     printf("%s%s%s\n",
           arrange_string("Hair Color: "+ob->query_hair_color(),25),
           arrange_string("Eye Color: "+ob->query_eye_color(),25),
           arrange_string("Subrace: "+ob->query("subrace"), 25) );

/*
  printf("%s%s%s\n",
    arrange_string(sp+"/"+max_sp+" Stamina Points", 25),
    arrange_string(mp+"/"+max_mp+" Magic Points", 25) );
*/
    printf("%s%s%s\n",
           arrange_string("Diety: "+capitalize(diety), 25),
           arrange_string("Sphere: "+capitalize(sphere), 25),
	     arrange_string("Domains: "+domain, 25));
    printf("%s%s%s\n",
           arrange_string("Carry: "+ob->query_internal_encumbrance(), 25) ,
           arrange_string("Max carry: "+ob->query_max_internal_encumbrance(), 25),
	     arrange_string("Damage Bonus: "+dam_bon, 25));
    printf("%s%s%s\n",
           arrange_string("Quest points: "+(int)ob->query_quest_points(), 25),
           arrange_string("Spouse: "+capitalize(married), 25),
	     arrange_string("Attack Bonus: "+at_bon, 25));

    printf("%s\n", arrange_string("Guild: "+guild, 80) );
    if (ob->is_player()) {
/****** Old ThAC0 code. ugly, my fault, Garrett.
     printf("%s/%s/%s/%s/%s\n", arrange_string("THAC0: "+ob->Thaco(1,ob,ob),15),
arrange_string("THAC0: "+ob->Thaco(2,ob,ob),15) ,
arrange_string("THAC0: "+ob->Thaco(3,ob,ob),15) ,
arrange_string("THAC0: "+ob->Thaco(4,ob,ob),15) ,
arrange_string("THAC0: "+ob->Thaco(5,ob,ob),15) );
- Garrett *****/
        show_quests(ob);
    }
    money_display(ob);
    stats_display(ob);
    return 1;
}

void show_quests(object ob)
{
    string *quests;
    int i;

    quests = (string *)ob->query_quests();    message("Nwrite", "Quests: ", TP);
    for (i=0; i<sizeof(quests); i++) {
        message("Nwrite", quests[i]+", ", TP);
    }
    message("Nwrite", "\n\n", TP);
}

void money_display(object ob) {
    string *currs;
    string borg;
    int tmp, i;

    currs = (string *)ob->query_currencies();
    if ((!currs || !sizeof(currs))) {
        message("info", "No money.", TP);
        return;
    }
    for (borg = "Money:\n", i=0, tmp = sizeof(currs); i<tmp; i++) {
        borg += ((ob->query_money(currs[i]))+" "+currs[i]);
        if (i == tmp-1) borg +=(".\n");
        else if (tmp > 2 && i == tmp-2) borg += (", and ");
        else if (tmp == 2) borg +=(" and ");
        else borg +=(", ");
    }
    message("info", borg, TP);
    return;
}

void stats_display(object ob)
{
    string str1, str2, str3;
    //tell_object(TP, "ob = "+identify(ob));
    vars["st"] = (int)ob->query_base_stats("strength");
    vars["in"] = (int)ob->query_base_stats("intelligence");
    vars["wi"] = (int)ob->query_base_stats("wisdom");
    vars["de"] = (int)ob->query_base_stats("dexterity");
    vars["co"] = (int)ob->query_base_stats("constitution");
    vars["ch"] = (int)ob->query_base_stats("charisma");

    vars["total_stats"] = vars["st"]+vars["in"]+vars["wi"]+vars["de"]+vars["co"]+vars["ch"];
    vars["add_pts"]=(int)ob->query("stat_points_gained");

    if(ob->query_base_stats("strength") != ob->query_stats("strength"))
        vars["st2"] = (int)ob->query_stats("strength");
    if(ob->query_base_stats("intelligence") != ob->query_stats("intelligence"))
        vars["in2"] = (int)ob->query_stats("intelligence");
    if(ob->query_base_stats("wisdom") != ob->query_stats("wisdom"))
        vars["wi2"] = (int)ob->query_stats("wisdom");
    if(ob->query_base_stats("dexterity") != ob->query_stats("dexterity"))
        vars["de2"] = (int)ob->query_stats("dexterity");
    if(ob->query_base_stats("constitution") != ob->query_stats("constitution"))
        vars["co2"] = (int)ob->query_stats("constitution");
    if(ob->query_base_stats("charisma") != ob->query_stats("charisma"))
        vars["ch2"] = (int)ob->query_stats("charisma");

    //estr = ob->query_stats("exceptional_strength");

    printf("Stats: (%d) Base. (%d) Add. [%d] Total.\n",vars["total_stats"]-vars["add_pts"],vars["add_pts"],vars["total_stats"]);
    /*if (estr != -1) {

        str1 = "Strength: "+st+"("+estr+")";
        if(st2) str1 += " ["+st2+"]";

        str2 = "Intelligence: "+in;
        if(in2) str2 += " ["+in2+"]";

        str3 = "Wisdom: "+wi;
        if(wi2) str3 += " ["+wi2+"]";

        printf("%s%s%s\n",
               arrange_string(str1,25),
               arrange_string(str2,25),
               arrange_string(str3,25) );
    } else {*/

        str1 = "Strength: "+vars["st"];
        if(vars["st2"]) str1 += " ["+vars["st2"]+"]";

        str2 = "Intelligence: "+vars["in"];
        if(vars["in2"]) str2 += " ["+vars["in2"]+"]";

        str3 = "Wisdom: "+vars["wi"];
        if(vars["wi2"]) str3 += " ["+vars["wi2"]+"]";

        printf("%s%s%s\n",
               arrange_string(str1,25),
               arrange_string(str2,25),
               arrange_string(str3, 25) );
    //}

        str1 = "Dexterity: "+vars["de"];
        if(vars["de2"]) str1 += " ["+vars["de2"]+"]";

        str2 = "Constitution: "+vars["co"];
        if(vars["co2"]) str2 += " ["+vars["co2"]+"]";

        str3 = "Charisma: "+vars["ch"];
        if(vars["ch2"]) str3 += " ["+vars["ch2"]+"]";

    printf("%s%s%s\n",
           arrange_string(str1,25),
           arrange_string(str2,25),
           arrange_string(str3, 25) );
    return;
}
