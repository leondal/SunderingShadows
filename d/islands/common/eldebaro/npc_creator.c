#include <std.h>
#include <dirs.h>
#include <daemons.h>

#define PRACES ([ "elf" : "elven", "human" : "human", "half-elf" : "half-elven", "half-orc" : "half-orcish", "gnome" : "gnomish", "halfling" : "halfling", "dwarf" : "dwarven" ])

#define CLASSES ({"fighter", "thief", "ranger", "cleric", "mage", "sorcerer", "psion", "psywarrior", "barbarian"})

#define COLORS ({"%^MAGENTA%^","%^YELLOW%^", "%^GREEN%^", "%^RED%^", "%^WHITE%^", "%^BLUE%^", "%^CYAN%^",\
                 "%^BOLD%^%^YELLOW%^", "%^BOLD%^%^GREEN%^", "%^BOLD%^%^RED%^", "%^BOLD%^%^BLACK%^", "%^BOLD%^%^WHITE%^",\
                 "%^BOLD%^%^CYAN%^", "%^BOLD%^%^BLUE%^", "%^BOLD%^%^MAGENTA%^", "%^RESET%^%^ORANGE%^"})
         
#define PBUILDS ({"well-built", "hardy", "stocky", "portly", "stout", "brawny", "massive", "heavy", "rotund"})                 

void equip_me(object ob)
{
    string *myClasses, myClass, *mySpells, *myFeats;
    string myClassFile;
    mapping tmp;
    object EQ;
    if(!objectp(ob)) return;
    if(!living(ob)) return;
    if(random(2)) ob->set_property("add kits",10 + random(16));
    
    myClasses = ob->query_classes();
    if(!pointerp(myClasses)) return;

    if(member_array("sorcerer", myClasses) != -1) myClass = "sorcerer";
    else if(member_array("mage", myClasses) != -1) myClass = "mage";
    else if(member_array("psion", myClasses) != -1) myClass = "psion";
    else if(member_array("cleric", myClasses) != -1) myClass = "cleric";
    else if(member_array("psywarrior", myClasses) != -1) myClass = "psywarrior";
    else if(member_array("ranger", myClasses) != -1) myClass = "ranger";
       
    if(stringp(myClass)) 
    {
        tmp = MAGIC_D->query_index(myClass);
        if(mapp(tmp)) mySpells = keys(tmp);
        if(pointerp(mySpells)) 
        {
            ob->set_spells(mySpells);
            ob->set_spell_chance(20 + random(31));
        }
    }
    if(member_array("barbarian", myClasses) != -1) myClass = "barbarian";
    else if(member_array("fighter", myClasses) != -1) myClass = "fighter";
    else if(member_array("ranger", myClasses) != -1) myClass = "ranger";
    else if(member_array("thief", myClasses) != -1) myClass = "thief";
    
    myClassFile = "/std/class/"+myClass+".c";
    if(file_exists(myClassFile))
    {
        myFeats = myClassFile->query_class_feats();
        if(!pointerp(myFeats)) myFeats = ({});
        myFeats += ({"perfect caster", "rush", "whirl"});
        ob->set_monster_feats(myFeats);
        ob->set_feat_chance(15 + random(21));
    }
    switch(myClass)
    {
        case "mage": case "sorcerer": case "psion":
            EQ = new("/d/common/obj/armour/robe");
            EQ->set_size((int)ob->query_size());
            if(random(100)) EQ->set_property("monsterweapon", 1);
            EQ->move(ob);
            EQ->set_property("enchantment", 5);
            ob->force_me("wear robe");
            EQ = new("/d/common/obj/armour/bracers");
            EQ->set_size((int)ob->query_size());
            if(random(100)) EQ->set_property("monsterweapon", 1);
            EQ->move(ob);
            EQ->set_property("enchantment", 5);
            ob->force_me("wear bracers");
            break;
        case "fighter": case "psywarrior":
            EQ = new("/d/common/obj/armour/fullplate");
            EQ->set_size((int)ob->query_size());
            if(random(100)) EQ->set_property("monsterweapon", 1);
            EQ->move(ob);
            EQ->set_property("enchantment", 5);
            ob->force_me("wear plate");
            EQ = new("/d/common/obj/armour/bracers");
            EQ->set_size((int)ob->query_size());
            if(random(100)) EQ->set_property("monsterweapon", 1);
            EQ->move(ob);
            EQ->set_property("enchantment", 5);
            ob->force_me("wear bracers");
            EQ = new("/d/common/obj/armour/mshield");
            EQ->set_size((int)ob->query_size());
            if(random(100)) EQ->set_property("monsterweapon", 1);
            EQ->move(ob);
            EQ->set_property("enchantment", 5);
            ob->force_me("wear shield");
            if((int)ob->query_size() == 1) EQ = new("/d/common/obj/weapon/shortsword");
            else EQ = new("/d/common/obj/weapon/longsword");           
            if(random(100)) EQ->set_property("monsterweapon", 1);
            EQ->move(ob);
            EQ->set_property("enchantment", 5);
            ob->force_me("wield sword");
            break;
        case "barbarian":
            EQ = new("/d/common/obj/armour/bracers");
            EQ->set_size((int)ob->query_size());
            if(random(100)) EQ->set_property("monsterweapon", 1);
            EQ->move(ob);
            EQ->set_property("enchantment", 5);
            ob->force_me("wear bracers");
            
            if((int)ob->query_size() == 1) EQ = new("/d/common/obj/weapon/shortsword");
            else EQ = new("/d/common/obj/weapon/longsword");   
            EQ->set_size((int)ob->query_size());
            if(random(100)) EQ->set_property("monsterweapon", 1);
            EQ->move(ob);
            EQ->set_property("enchantment", 5);
            ob->force_me("wield sword");
            
            if((int)ob->query_size() == 1) EQ = new("/d/common/obj/weapon/shortsword");
            else EQ = new("/d/common/obj/weapon/longsword");   
            EQ->set_size((int)ob->query_size());
            if(random(100)) EQ->set_property("monsterweapon", 1);
            EQ->move(ob);
            EQ->set_property("enchantment", 5);
            ob->force_me("wield sword");
            break;
        case "cleric":
            EQ = new("/d/common/obj/armour/fullplate");
            EQ->set_size((int)ob->query_size());
            if(random(100)) EQ->set_property("monsterweapon", 1);
            EQ->move(ob);
            EQ->set_property("enchantment", 5);
            ob->force_me("wear plate");
            EQ = new("/d/common/obj/armour/bracers");
            EQ->set_size((int)ob->query_size());
            if(random(100)) EQ->set_property("monsterweapon", 1);
            EQ->move(ob);
            EQ->set_property("enchantment", 5);
            ob->force_me("wear bracers");
            EQ = new("/d/common/obj/armour/mshield");
            EQ->set_size((int)ob->query_size());
            if(random(100)) EQ->set_property("monsterweapon", 1);
            EQ->move(ob);
            EQ->set_property("enchantment", 5);
            ob->force_me("wear shield");
            if((int)ob->query_size() == 1) EQ = new("/d/common/obj/weapon/sickle");
            else EQ = new("/d/common/obj/weapon/flail");           
            if(random(100)) EQ->set_property("monsterweapon", 1);
            EQ->move(ob);
            EQ->set_property("enchantment", 5);
            ob->force_me("wield flail");
            ob->force_me("wield sickle");
            break;
        case "ranger": case "thief":
            EQ = new("/d/common/obj/armour/studded");
            EQ->set_size((int)ob->query_size());
            if(random(100)) EQ->set_property("monsterweapon", 1);
            EQ->move(ob);
            EQ->set_property("enchantment", 5);
            ob->force_me("wear armor");
            EQ = new("/d/common/obj/armour/bracers");
            EQ->set_size((int)ob->query_size());
            if(random(100)) EQ->set_property("monsterweapon", 1);
            EQ->move(ob);
            EQ->set_property("enchantment", 5);
            ob->force_me("wear bracers");
            if((int)ob->query_size() == 1) EQ = new("/d/common/obj/weapon/shortsword");
            else EQ = new("/d/common/obj/weapon/longsword");           
            if(random(100)) EQ->set_property("monsterweapon", 1);
            EQ->move(ob);
            EQ->set_property("enchantment", 5);
            ob->force_me("wield sword");
            if((int)ob->query_size() == 1) EQ = new("/d/common/obj/weapon/shortsword");
            else EQ = new("/d/common/obj/weapon/longsword");           
            if(random(100)) EQ->set_property("monsterweapon", 1);
            EQ->move(ob);
            EQ->set_property("enchantment", 5);
            ob->force_me("wield sword");
            break;           
    }
    /*ob->set_func(({"backup"}));
    ob->set_func_chance(25);*/
}




void build_me(object ob)
{
    int lev;
    string *eye_colors, *hair_colors, ec, hc, EC, HC, MC, HIM, HE, HIS;
    string myClass, myBuild, myRace, myRaceDes, *races, *myClassTwo, myRaceFile;
    string *pcols, *pclasses;
    if(!objectp(ob)) return;
    if(!living(ob)) return;
    lev = 35 + random(11);
    
    myClass = CLASSES[random(sizeof(CLASSES))];   
        
    ob->set_class(myClass);
    ob->set_guild_level(myClass, lev);
    ob->set_mlevel(myClass, lev);  
    pclasses = CLASSES;
    if(!random(3))
    {
        pclasses -= ({myClass});
        myClassTwo = pclasses[random(sizeof(pclasses))];
                
        lev = 35 + random(11);
        ob->set_guild_level(myClassTwo, lev);
        ob->set_mlevel(myClassTwo, lev);
    }
    ob->set_max_hp((lev*(40 + random(21))));
    ob->set_hp((int)ob->query_max_hp());
    races = keys(PRACES);
    myRace = races[random(sizeof(races))];
    ob->set_race(myRace);
    ob->set_property("full attacks", 1);
    switch(myClass)
    {
        case "fighter": case "barbarian":
            ob->set_stats("strength", 26);
            ob->set_stats("dexterity", 18);
            ob->set_stats("constitution", 22);
            ob->set_stats("wisdom", 12);
            ob->set_stats("charisma", 12);
            ob->set_stats("intelligence", 12);
            break;
        case "thief": case "ranger":
            ob->set_stats("dexterity", 26);
            ob->set_stats("strength", 18);
            ob->set_stats("constitution", 21);
            ob->set_stats("wisdom", 14);
            ob->set_stats("intelligence", 12);
            ob->set_stats("charisma", 13);
            break;
        case "cleric":
            ob->set_stats("strength", 18);
            ob->set_stats("wisdom", 25);
            ob->set_stats("dexterity", 12);
            ob->set_stats("constitution", 16);
            ob->set_stats("charisma", 12);
            ob->set_stats("intelligence", 14);
            break;
        case "mage": case "psion":
            ob->set_stats("strength", 14);
            ob->set_stats("wisdom", 14);
            ob->set_stats("dexterity", 18);
            ob->set_stats("constitution", 18);
            ob->set_stats("charisma", 12);
            ob->set_stats("intelligence", 26);
            break;
        case "sorcerer":
            ob->set_stats("strength", 15);
            ob->set_stats("wisdom", 14);
            ob->set_stats("dexterity", 18);
            ob->set_stats("constitution", 18);
            ob->set_stats("charisma", 25);
            ob->set_stats("intelligence", 14);
            break;
        case "psywarrior":
            ob->set_stats("strength", 19);
            ob->set_stats("wisdom", 14);
            ob->set_stats("dexterity", 16);
            ob->set_stats("constitution", 17);
            ob->set_stats("charisma", 12);
            ob->set_stats("intelligence", 22);
            break;
    }
    
    if(myRace == "half-orc") 
    {
        if(random(2)) myRaceFile = "/std/races/elf.c";
        else myRaceFile = "/std/races/orc.c";            
    }
    else if(myRace == "half-elf")
    {
        if(random(2)) myRaceFile = "/std/races/elf.c";
        else myRaceFile = "/std/races/human.c";            
    }
    else myRaceFile = "/std/races/"+myRace+".c";
    if(file_exists(myRaceFile))
    {
        eye_colors = myRaceFile->query_eye_colors(ob);
        hair_colors = myRaceFile->query_hair_colors(ob);      
    }
    if(pointerp(hair_colors)) hc = hair_colors[random(sizeof(hair_colors))];
    else hc = "brown";
    if(pointerp(eye_colors)) ec = eye_colors[random(sizeof(eye_colors))];
    else ec = "blue";
    
    myRaceDes = PRACES[myRace];
    
    
    if(random(2)) ob->set_gender("male");
    else ob->set_gender("female");
    
    HIM = ob->QO;
    HE = ob->QS;
    HIS = ob->QP;
    
    myBuild = PBUILDS[random(sizeof(PBUILDS))];
    
    ob->set_id(({"nomad", myBuild + " nomad", myRace, "mysterious nomad"}));
    
    ob->set_name(myBuild + " " + (string)ob->query_gender() + " " + myRaceDes + " nomad");
    
    
    pcols = COLORS;
    EC = "%^RESET%^"+pcols[random(sizeof(pcols))];
    pcols -= ({EC});
    HC = "%^RESET%^"+pcols[random(sizeof(pcols))];
    pcols -= ({HC});
    MC = "%^RESET%^"+pcols[random(sizeof(pcols))];
    
    ob->set_short(MC+myBuild + " " + (string)ob->query_gender() + " " + myRaceDes + " nomad with "+EC+ec+" eyes%^RESET%^"+MC+" and "+HC+hc+" hair%^RESET%^");
    ob->set_overall_ac(-5);
    ob->set_new_exp("35", "normal");
    
    ob->set_long(MC+"This "+myBuild+" "+myRace+" looks weary, as if "+HE+" has been through a lot recently. "+
    capitalize(HIS)+" bright "+EC+ec+" eyes"+MC+", however, reflect a deep and unwavering determination. As if "+
    HE+" is not giving up any time soon. "+capitalize(HIS)+" "+myBuild+" body also looks exceptionally tense, as if "+HE+
    " is expecting danger or confrontation at any time. "+capitalize(HIS)+" "+HC+hc+" hair"+MC+" is kept neat and "+
    "tidy most of the time and "+HE+" ocassionally runs "+HIS+" fingers through it to remove the ever "+
    "present sand. A strange symbol has been embedded into each of "+HIS+" earlobes, each glows and pulses "+
    "constantly.%^RESET%^");
    
    equip_me(ob);
    ob->set_property("eldebaro_built", 1);
    return;
    
}