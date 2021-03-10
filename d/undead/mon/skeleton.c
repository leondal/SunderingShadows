#include <std.h>
#include "../undead.h"

inherit CREATURE;

void create() 
{
    object ob;
    ::create();
    set_name("skeleton warrior");
    set_id(({"skeleton","warrior","skeleton warrior"}));
    set_short("Skeleton Warrior");
    set_long("The Skeleton Warriors are harvested from Kartakass's undead "
        "army to serve as patrollers of the Peth Forest. Kartakass seems overly "
        "paranoid of anyone getting near the desert, so he sends some of his "
        "best to stand guard.");
    set_race("undead");
    set_gender("male");
    set_hd(20,9);
    set_size(2);
    set_overall_ac(0);
    set_class("fighter");
    set_guild_level("fighter",20);
    add_search_path( "cmds/fighter" );
    set_hp(300);
    set_body_type("human");
    set_property("swarm",1);
    set_property("full attacks",1);
    set_stats("strength",19);
    set_stats("dexterity",16);
    set_stats("constitution",19);
    set("aggressive",22);
    set_speed(35);
    nogo("one");
    set_exp(5000);
    set_new_exp(25,"normal");
    set_alignment(9);
    set_funcs(({"gaze"}));
    set_func_chance(15);
    ob = new(CWEAP"two_hand_sword.c");
    ob->set_property("monsterweapon",1);
    ob->set_property("enchantment",2);
    ob->move(TO);
    command("wield sword");
    if(!random(4)) { set_property("add kits",roll_dice(2,10)); }
    add_money("gold",random(1000));
    add_money("platinum",random(50));
    if(!random(20)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("bone dust");
      ob->move(TO);
    }
    set_resistance("negative energy",10);
    set_resistance("positive energy",-10); 
}

void gaze(object targ) 
{
    tell_object(targ,"%^RED%^The skeleton warrior stares at your eyes, "
        "and peers into your soul.");
    tell_object(targ,"%^BOLD%^%^BLUE%^You realize just how evil a creature "
        "you are and wish someone would just kill you.");
    tell_room(ETO,"%^RED%^The skeleton warrior stares at "+targ->QCN+"'s "
        "eyes.",targ);
    targ->force_me("scream");
    targ->set_paralyzed(roll_dice(3,8),"You can't tear your eyes away from "
        "the creature's gaze!");
    return 1;
}
