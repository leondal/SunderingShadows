#include <std.h>
#include "../derrodefs.h"
inherit MONSTER;

object ob, targ;

void create()
{
    ::create();
    set_name("firegiant king");
    set_id(({"giant","fire giant","king","ravhas"}));
    set_race("giant");
    set_gender("male");
    set_short("%^BOLD%^%^RED%^Ravhas, king of the firegiants");
    set_long("This massive creature is a sight to make you tremble with fear.   His massive "
        "frame is fully armored and he has a great sword that takes two hands for this 18 foot "
        "tall giant to wield.  This fire giant king is most upset about whats happened to his "
        "clan and doesnt look to happy to see anyone else here let alone you!  Perhaps you could "
        "try to calm him?");
    set_ac(-5);
    set_mob_magic_resistance("average");
    set_mlevel(39);
    add_search_path("/cmds/fighter");
    set("aggressive","agggunc");
    set_alignment(9);
    set_hd(39,2);
    set_property("full attacks",1);
    set_stats("strength",24);
    set_stats("intelligence",13);
    set_stats("wisdom",15);
    set_stats("dexterity",18);
    set_stats("constitution",19);
    set_stats("charisma",13);
    set_guild_level("fighter",35);
    ob=new("/d/common/obj/rand/rand_shirts.c");
    if(random(2)) { ob->set_property("monsterweapon",1); }
    ob->set_property("enchantment",1);
    ob->move(TO);
    new(OBJ"fireplate.c")->move(TO);
    new(OBJ"steelhelm.c")->move(TO);
    //Added to put another Katana IG sometimes - Saide - 10/16/04
    switch(random(2)) 
    {
    case 0:
        new(OBJ"flameblade.c")->move(TO);
        break;
    case 1:
        new(OBJ"sildorekatana.c")->move(TO);
        break;
    }

    new(OBJ"greatcloak.c")->move(TO);
    //if(!random(2)) present("greatcloak",TO)->set_property("monsterweapon",1);
    if(!random(2)) present("helm",TO)->set_property("monsterweapon",1);
    if(!random(2)) present("plate",TO)->set_property("monsterweapon",1);
    if(!random(2)) present("sword",TO)->set_property("monsterweapon",1);
    command("wield sword");
    command("wear cloak");
    command("wear plate");
    command("wear helmet");
    command("wear shirt");
    add_money("gold",200+random(1000));
    set_hp(500);
    set_exp(20000);
    set("aggressive","agg_func");
    set_stabbed_func((:TO,"stabbed":));
    remove_property("swarm");
}

void init()
{
    ::init();
    add_action("ask","ask");
    add_action("calm","calm");
}

int calm(string str)
{
    tell_room(ETO,"%^MAGENTA%^Firegiant king says:%^RESET%^ Hmm.   You dont appear "
        "to be minions of the derro.  I have little time for you puny one if you "
        "have question %^BOLD%^ask about%^RESET%^ them and be off with you before "
        "I burn you where you stand!\n");
}

void receive_given_item(object item)
{
    object *targ;
    int i,j;
    if(present("ornate secari",TO))
    {
        message("environment", "%^BOLD%^%^RED%^Ravhas roars and grabs the dagger and with one "
            "massive stroke smashes it with his flaming sword.\n"
            "%^BOLD%^%^WHITE%^BAH! I could of done that same if I could sneak past the ones who "
            "guard my door, but no matter with them I'll deal with them when I feel fit!\n"
            "%^BOLD%^%^RED%^Our home has no exits, we sealed it off with a great block of stone "
            "that only allows those who befriend it through.\n"
            "%^BOLD%^WHITE%^  Go talk with my earth priest who I hear the Derro have captured, "
            "he can tell you how to do the %^CYAN%^deed%^WHITE%^ required to leave.\n",environment(TO));
    
        ob=present("ornate secari",TO);
        ob->remove();
        targ=all_living(ETO);
        j=sizeof(targ);
        for(i=0;i<j;i++)
        {
            targ[i]->set("TRusted",1);
        }
    }
}
int ask(string str)
{
    if((str=="about captive")||(str=="about wounded captive"))
    {
        message("environment","%^MAGENTA%^King says:%^RESET%^ Ahh, yes my earth priest.   Lot "
            "of good he did convincing me to free that %^RED%^being%^RESET%^ from the lava.  "
            "Wounded after the thing attacked and then wandered into the %^BLUE%^Derro%^RESET%^s "
            "clutches.\n Knows a lot though and will be the one who can show you "
            "the %^BOLD%^way out%^RESET%^.",environment(TO));
        return 1;
    }
    
    if((str=="about way out"))
    {
        message("environment","\n %^MAGENTA%^Firegiant King says:%^RESET%^ The entrance to my "
            "kingdom was sealed with a block of stone that allows only those it knows through.  "
            "My earth priest knows how to befriend it and from what I hear that bastard %^BLUE%^"
            "savant%^RESET%^ figured out a way as well",environment(TO));
        return 1;
    }

    if((str=="about being"))
    {
        message("environment","\n%^BOLD%^%^WHITE%^The kings knuckles go white as he clutches his "
            "massive flaming sword!\n\n%^RESET%^%^MAGENTA%^Firegiant king says:%^RESET%^That thing "
            "was just to much! I've hunted dragons and fought the surface dwellers armies for ages "
            "but I've never come across anything of its likes.   Beware if you should cross its paths, "
            "it destroyed my clan!",environment(TO));
        return 1;
    }

    if((str=="about derro")||(str=="about Derro"))
    {
        message("environment","\n%^MAGENTA%^Firegiant King says:%^RESET%^ Those pale little bastards.  "
            "I thought mountain dwarves were bad enough and then these little freaks burrow up from the "
            "depths for who knows what reason at the command of thier %^BLUE%^savant%^RESET%^."
            "\n  They swarm all over the place and they work well with the magic of the %^BLUE%^"
            "students%^RESET%^ of the %^BLUE%^savant%^ to well!",environment(TO));
        return 1;
    }

    if((str=="about savant"))
    {
        message("environment","\n%^MAGENTA%^Firegiant King says:%^RESET%^ He is the master of the "
            "group here.  I dont know what he is up here for but his magic powers are great and his "
            "mind keen enough to take advantage of my dire circumstances.  Why he hasnt commanded his "
            "little maggots to swarm me here I dont know but they're happy to just swarm my kingdom "
            "searching for something.\n  His death would make me trust you a little more than I "
            "should,  bring me his %^BLUE%^secari.",environment(TO));
        return 1;
    }

    if((str=="about students"))
    {
        message("environment","\n%^MAGENTA%^Firegiant King says:%^RESET%^ Magic using dwarves "
            "struggling to gain enough power to usurp thier master %^BLUE%^savant%^RESET%^."
            "  They hold the masses of derro warriors in thrall in thier search for spells "
            "and devices of arcane power.",environment(TO));
        return 1;
    }

    if((str=="about secari"))
    {
        message("environment","\n%^MAGENTA%^Firegiant King says:%^RESET%^ The secaris are the "
            "daggers the %^BLUE%^Derro%^RESET%^ carry.   The ones the warrios carry are so "
            "pathectic as to be worthless, but the ones the %^BLUE%^savant%^RESET%^ and his "
            "%^BLUE%^students%^RESET%^ carry are empowered with magic power.\n  Give me the "
            "secari the %^BLUE%^savant%^RESET%^ carries and I'll think more about letting you "
            "leave.",environment(TO));
        return 1;
    }

    if((str=="about deed"))
    {
        message("environment","\Ask the captive about it.",environment(TO));
        return 1;
    }
}

void heart_beat()
{
    int i,j;
    object *att;

    ::heart_beat();

    if(!objectp(TO) || !objectp(ETO)) return;

    if(present("secari",TP))
    {
        tell_room(ETO,"%^MAGENTA%^Firegiants kings says:%^RESET%^ Bah this one is "
            "from the weak students.  Means nothing.%^RESET%^\n");
        command("offer secari");
    }
    
    if(present("coins",ETO)) { command("get coins"); }

    if(present("derro",ETO)) { command("rush derro"); }

    if(query_hp()<490) { TP->add_hp(1); }

    if((att=(object *)TO->query_attackers()) !=({}))
    {
        j=sizeof(att);
        for(i=0;i<j;i++)
        {
            if(living(att[i]) && !userp(att[i]))
            {
                tell_room(ETO,"%^BOLD%^%^RED%^The king roars and "+att[i]->query_name()+" flees in terror!");
                att[i]->run_away();
            }
            if(att[i]->query_highest_level()>30)
            {
                call_out("force_me",2,"rush "+att[i]->query_name());
            }
        }
    }
}

void stabbed()
{
    if(!objectp(TP) || !objectp(TO) || !objectp(ETO)) { return; }
    TP->set_disabled(5);
    tell_room(ETO,"%^BOLD%^%^RED%^The kings armor prevents the full force of the stab!");
    if(query_hp()<0) set_hp(100);
}
