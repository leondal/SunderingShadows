// Vishnu Bokara, dealer in strange and mystical wares
// Thorn@ShadowGate
// 4/9/96
// Town of Azha
// bokara.c

#include <std.h>

inherit "/std/vendor";

create() {
   ::create();
   set_name("Bokara");
   set_id( ({ "bokara", "vishnu", "merchant", "dealer" }) );
   set_short("Vishnu Bokara, Dealer in Strange and Mystical Wares");
   set("aggressive", 0);
   set_level(19);
   set_long(
@AZHA
  This strange little man, is clad from head to toe in a black cloak
embroidered with little golden stars and moons.  Even in the sunniest
weather, a black hood covers his head, lending only the most cursory
looks at his face.  It is rumored in the markets that Bokara is not
human, but rather an elf, possibly even a drow.  Either way, his
demeanor and the stories about him are perfect for the strange things
this merchant peddles in this square.
AZHA
   );
   set_languages( ({ "common" }) );
   set_gender("male");
   set_alignment(7);
   set("race", "unknown");
   add_money("gold", random(500));
   set_body_type("human");
   set_property("no attack", 1);
   set_hd(19,3);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(500));
   set_max_mp(query_mp());
   set_storage_room("/d/azha/town/bokara_storage.c");
   set_exp(0);
   remove_random_act_dbs(({"armorrandom"}));
}
