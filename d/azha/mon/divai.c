// Divai, Barber and Surgeon of Azha
// Thorn@ShadowGate
// 4/13/96
// Town of Azha
// divai.c

#include <std.h>

inherit TOWNSMAN;

create() {
   ::create();
   set_name("Divai");
   set_id( ({ "divai", "healer", "barber", "surgeon" }) );
   set_short("Divai, Barber and Surgeon of Azha");
   set_long(
@AZHA
  Divai is one of the oldest men in Azha Province.  It is rumored
that his father was an Imperial Guard who came to Azha during the
War of the Black Hand, with the hosts of the Celestial Emperor. His
more than 95 years has given him the knowledge and experience to
become an excellent barber and very good healer.
AZHA
   );
   set_languages( ({ "common" }) );
   set_gender("male");
   set_class("mage");
   level = 24;
    set_hd(level,1);
   set_level(level);
   set_mob_magic_resistance("average");
   set_alignment(1);
   set_race("human");
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
	 set_hd(level,4);
	 set_max_hp(query_hp());
	 set_wielding_limbs( ({ "right hand", "left hand" }) );
}
