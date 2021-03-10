#include <castle.h>

inherit "/std/monster";

void create() {
        object sword,armour;
    ::create();
	set_name("guard");
	set_id( ({ "guard", "castle guard" }) );
	set_race("human");
	set_gender("male");
	set("short", "Castle guard");
	set("long", "A real soldier assigned to guard the gates of this castle.\n");
	set_level(8);
	set_body_type("human");
	set_class("fighter");
  	set("aggressive", 0);
  	set_alignment(7);
  	set_size(2);
   	set_stats("intelligence",6);
   	set_stats("wisdom",4);
   	set_stats("strength",13);
   	set_stats("charisma",3);
   	set_stats("dexterity",8);
   	set_stats("constitution",7);
	set_hd(8, 0);
	set_max_hp(query_hp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
        sword = new("/d/common/obj/weapon/broad");
	sword->set_name("castlesword");
	sword->set_id( ({"sword","broadsword","guard's sword"}) );
	sword->set_short("A nice broadsword, used by the castle guards");
	sword->set_long("A broadsword, used by the guards of Marleen's castle");
        sword->set_value(12);
        sword->move(this_object());
      	command("wield broadsword");
	armour = new("/d/common/obj/armour/chain");
	armour->set_name("castle chainmail");
	armour->set_id( ({"chain","chainmail","castle chain"}) );
	armour->set_short("A chainmail with a golden emblem on it");
	armour->set_long("A chainmail with the emblem of Marleen's castle depicted on it. It looks like a good armour!");
	armour->set_value(70);
	armour->move(this_object());
      	command("wear chain");
}