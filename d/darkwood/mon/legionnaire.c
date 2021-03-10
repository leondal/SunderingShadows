#include <std.h>
#include "/d/darkwood/darcy/darcy.h"

inherit "/std/monster";

int count;

void create(){
        object ob, ob2;
        ::create();

        set_name("Death's Head Legionnaire");
        set_id(({"legionnaire","guard","deaths head", 
        "death", "death legionnaire", "deaths head legionnaire"}));
        set("short","A Death's Head Legionnaire");
        set("long",
@DARKWOOD
  This is one of the most feared soldiers in the Middle Kingdoms of
Shadow, a member of the Death's Head Legion of Lord Kai.  These
troops are well-armed, well trained and fight to the last gasp.  It
is rumored that these troops are bound together by a secret power so
dark that it is only whispered about.

DARKWOOD
        );
        set_hd(20,3);
        set_hp(200);
        set_exp(10000);
        set_mob_magic_resistance("average");
        set_property("swarm",1);
        set_stats("strength",19);
        set_stats("constitution",17);
        set_stats("dexterity",16);
        set_stats("intelligence",7);
        set_stats("wisdom",15);
        set_stats("charisma",5);
        set_body_type("human");
        set_race("human");
        set_alignment(7);
        set_overall_ac(7);
        set_gender("male");
        set_wielding_limbs(({"right hand","left hand"}));
        ob=new("/d/shadow/obj/weapon/longsword");
        ob->set_short("Legionnaire's Sword");
        ob->set_property("enchantment",2);
        if(random(20) < 19) ob->set_property("monsterweapon",1);
        ob->move(TO);
        command("wield sword in right hand");
        ob=new("/d/shadow/obj/weapon/dagger");
        ob->set_short("Legionnaire's Dagger");
        ob->set_property("enchantment",3);
        if(random(20) < 19) ob->set_property("monsterweapon",1);
        ob->move(TO);
        command("wield dagger in left hand");
        ob=new("/d/shadow/obj/armor/fullplate");
        ob->set_short("Death's Head Legion full plate armor");
        ob->set_id(({"full plate","legion plate","deaths head plate", "plate"
        "legion armor", "legionnaire plate", "deaths head legion full plate"}));        
        ob->set_property("enchantment",2);
        if(random(40) < 39) ob->set_property("monsterweapon",1);
        ob->move(TO);
        command("wear legion plate");
        ob=new("/d/shadow/obj/armor/coif");
        ob->set_short("Coif of the Legion");
        ob->set_id(({"coif","legion coif","coif of the legion"}));        
        ob->set_property("enchantment",2);
        if(random(30) < 29) ob->set_property("monsterweapon",1);
        ob->move(TO);        
        command("wear coif");
}

die() {
	object ob;

	if(ob=present("deaths head legionnaire 2", environment(TO))) {
		say("%^BLUE%^BOLD%^As the legionnaire dies, you see energy"+
		" flow from his body into his comrade at his side, making "+
		"his comrade more powerful!");
		ob->set_mob_magic_resistance("average");
		ob->set_max_hp(ob->query_max_hp()+120);
		ob->do_damage(0,-120);
	}
	::die();	
}
