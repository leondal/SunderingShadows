// A nice stableboy
// Pator@ShadowGate
// 04/18/95
#include <castle.h>

inherit "/std/monster";

void create() {
        ::create();
	set_name("stableboy");
	set_id( ({ "boy", "stableboy" }) );
	set("race", "human");
	set_gender("male");
	set("short", "Stable boy");
    set("long", "A young boy busy cleaning the stables.  He is naughty sometimes and then he has to clean the stables even at night!\n");
	set_level(4);
	set_body_type("human");
	set_class("fighter");
  	set("aggressive", 0);
  	set_size(2);
   	set_stats("intelligence",5);
   	set_stats("wisdom",3);
   	set_stats("strength",10);
   	set_stats("charisma",12);
   	set_stats("dexterity",8);
   	set_stats("constitution",7);
   	set_max_mp(0);
   	set_mp(0);
	set_hd(6, 0);
        set_hp(25);
	set_max_hp(query_hp());
	set_max_sp(query_hp());
 	set_sp(query_max_sp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
        new("/d/deku/open/castle/object/shovel")->move(this_object());
      	command("wield shovel in right hand");
	
}






