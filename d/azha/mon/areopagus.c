// John Areopagus, a northern merchant
// Thorn@ShadowGate
// 4/13/96
// Town of Azha
// areopagus.c

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

inherit MONSTER;

create() {
   ::create();
   set_name("Areopagus");
   set_id( ({ "john", "areopagus", "merchant"}) );
   set_short("John Areopagus");
   set_long(
@AZHA
  John Areopagus is a big, burly merchant from the far north.  He 
usually deals in timber and does some iron exporting.  Right now, he's
a little irritated at the hassle that he is getting in Customs over
some stuff that he imported this time.  You see that he is clutching
his very large battleaxe VERY tightly, in his left hand.
AZHA
   );
   set_languages( ({ "common" }) );
   set_gender("male");
   set_class("fighter");
   level = 14;
   set_hd(level,10);
   set_alignment(2);
   set("race", "human");
   add_money("gold", random(150)+250);
   set_body_type("human");
   set_size(2);
	 set_stats("strength", 23);
	 set_stats("constitution", 16);
	 set_stats("wisdom", 11);
	 set_stats("charisma", 13);
	 set_stats("intelligence", 10);
	 set_stats("dexterity", 17);
	 set_max_mp(0);
	 set_mp(query_max_mp());
	 set_hp(400);
	 set_max_hp(query_hp());
	 set_max_sp(query_hp());
	 set_sp(query_max_sp());
	 set_wielding_limbs( ({ "right hand", "left hand" }) );
	 new(AEQUIP+"a_axe.c")->move(TO);
	 force_me("wield axe in left hand");
}
