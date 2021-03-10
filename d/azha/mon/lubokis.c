// Vitas Lubokis, Clerk of Azha
// Thorn@ShadowGate
// 4/13/96
// Town of Azha
// lubokis.c

#include <std.h>

inherit MONSTER;

create() {
   ::create();
   set_name("Lubokis");
   set_id( ({ "clerk", "lubokis", "vitas"}) );
   set_short("Vitas Lubokis, Clerk of Azha");
   set_long(
@AZHA
  Vitas Lubokis is a middle-aged, geeky-looking individual
who handles all of the administrivia of the town government.
He will give out all sorts of permits...for a price.
AZHA
   );
   set_languages( ({ "common" }) );
   set_gender("male");
   set_class("fighter");
   level = 1;
   set_level(level);
   set_alignment(1);
   set("race", "human");
   add_money("silver", random(3)+5);
   set_body_type("human");
   set_size(2);
	 set_stats("strength", 10);
	 set_stats("constitution", 9);
	 set_stats("wisdom", 12);
	 set_stats("charisma", 8);
	 set_stats("intelligence", 13);
	 set_stats("dexterity", 11);
	 set_max_mp(0);
	 set_mp(query_max_mp());
	 set_hd(level,1);
	 set_max_hp(query_hp());
	 set_max_sp(query_hp());
	 set_sp(query_max_sp());
	 set_wielding_limbs( ({ "right hand", "left hand" }) );
}
