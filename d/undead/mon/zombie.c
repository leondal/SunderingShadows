#include <std.h>
#include "../undead.h"

inherit CREATURE;

void create() 
{
    object ob;
    ::create();
    set_name("zombie");
    set_id(({"zombie","undead"}));
    set_short("Zombie warrior");
    set_long("The Zombie warrior is one of hundreds of zombies serving their undead "
        "lord, Kartakass. It is rumored that they are in fact the bodies of"
        "fallen hero's brought back to fight for the side of evil.");
    set_race("undead");
    set_gender("male");
    set_hd(8,8);
    set_size(2);
    set_overall_ac(1);
    set_class("fighter");
    set_guild_level("fighter", 18);
    add_search_path( "cmds/fighter" );
    set_hp(200);
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("humanoid");
    set_property("swarm",1);
    set_property("full attacks",1);
    set_property("no bump",1);
    set_stats("strength", 16);
    set_stats("dexterity",16);
    set_stats("constitution",19);
    set("aggressive","aggfunc");
    set_exp(5000);
    set_new_exp(25,"normal");
    set_speed(40);
    nogo("one");
    set_alignment(9);
    set_funcs(({"bite"}));
    set_func_chance(10);
    ob = new(WEAPONDIR+"bastard.c");
    ob->set_property("monsterweapon",1);
    ob->move(TO);
    command("wield sword");
    set_resistance("negative energy",10);
    set_resistance("positive energy",-10); 
}

void bite(object targ) 
{
	string *ids;

    if(targ->query_true_invis()) { return; }

	ids = targ->query_id();
    tell_object(targ,"%^BOLD%^%^RED%^The Zombie lunges at you!%^RESET%^");
    if((int)targ->query_stats("dexterity") < random(25))
    {
        tell_object(targ,"%^RED%^The Zombie grabs you and begins to tear into your flesh with an inhuman force!%^RESET%^");
        tell_room(ETO,"%^BOLD%^%^RED%^The Zombie lunges at "+targ->query_cap_name()+"!%^RESET%^",targ);
        tell_room(ETO,"%^RED%^The Zombie grabs "+targ->query_cap_name()+" and begins to tear away his flesh!%^RESET%^",targ);
        TO->set_property("magic",1);
        targ->do_damage("torso",roll_dice(3,6));
        TO->remove_property("magic");
    }
	TO->force_me("kill "+ids[0]+"");
    kill_ob(targ,1);
    return 1;
}

void aggfunc() 
{
    if ((string)TP->query_race() == "undead" || TP->query_invis()) { command("cackle"); } 
    else { command("say It will be an honor to bring your head to the master!"); call_out("bite",1,TP); }
}
