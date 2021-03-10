#include <std.h>
#include "/d/darkwood/darcy/darcy.h"

inherit "/std/monster";

int count;

void create(){
        object ob;
        ::create();

        set_name("elite mercenary");
        set_id(({"mercenary","soldier","mercenary soldier", 
        "elite", "elite soldier", "elite mercenary soldier"}));
        set("short","An elite mercenary soldier");
        set("long",
@DARKWOOD
  This warrior is one of a group of elite mercenary soldiers hired
by the mage Aloysius to take over and then hold the Chateau d'Arcy
against the remains of the Marquis' army.  From the scars on his
face, you can tell this man is no mere brute, but a veteran soldier
turned mercenary-for-hire.

DARKWOOD
        );
        set_hd(17,3);
        set_hp(120);
        set_exp(5000);
        set_mob_magic_resistance("average");
        set_property("swarm",1);
        set_stats("strength",19);
        set_stats("constitution",17);
        set_stats("dexterity",17);
        set_stats("intelligence",7);
        set_stats("wisdom",15);
        set_stats("charisma",5);
        set_body_type("human");
        set_race("human");
        set_alignment(7);
        set_overall_ac(7);
        set_gender("male");
        set_wielding_limbs(({"right hand","left hand"}));
        ob = new("/d/shadow/obj/weapon/longsword");
        ob->set_property("enchantment",1);
        if(random(40) < 39) ob->set_property("monsterweapon",1);
        ob->move(TO);
        command("wield sword in right hand");
        ob = new("/d/shadow/obj/weapon/longsword");
        ob->set_property("enchantment",1);
        if(random(40) < 39) ob->set_property("monsterweapon",1);
        ob->move(TO);
        command("wield sword in left hand");
        ob=new("/d/shadow/obj/armor/fullplate");
        ob->set_property("enchantment",1);
        ob->set_property("monsterweapon",1);
        ob->move(TO);
        command("wear armor");
}
