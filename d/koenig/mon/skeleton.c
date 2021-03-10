//skeleton.c - updated for Koenig by Circe 11/29/03
#include <std.h>
#include <daemons.h>
inherit MONSTER;

void create() {
    	::create();
	set_name("skeleton");
	set_id(({"skeleton","monster","undead"}));
	set_race("undead");
	set_gender("male");
	set_short("skeleton");
	set_long("The bones of this creature are dirty, with ragged clothing and "+
         "bits of flesh still hanging on.  Given the size and shape of the bones, "+
         "the creature was clearly a human - most likely one of the poor villagers.  "+
         "It now mindlessly serves its master, using the shortsword it wields on any "+
         "that come near.");
	set_level(4);
	set_body_type("human");
	set_class("fighter");
  	set_alignment(9);
  	set_size(2);
      set_property("swarm",1);
   	set_stats("intelligence",6);
   	set_stats("wisdom",4);
   	set_stats("strength",14);
   	set_stats("charisma",3);
   	set_stats("dexterity",8);
   	set_stats("constitution",7);
   	set_max_level(7);
      set_hd(4,8);
	set_max_hp(random(40) + 30);
	set_hp(query_max_hp());
      set_exp(550+random(75));
	set_wielding_limbs( ({ "right hand", "left hand" }) );
        	new("/d/common/obj/weapon/shortsword")->move(TO);
        	command("wield sword");
	add_money("electrum",random(10));
	add_money("silver",random(10));
	add_money("gold",random(5));
	add_money("copper",random(20));
	set_property("undead",1);
      set_overall_ac(5);
}