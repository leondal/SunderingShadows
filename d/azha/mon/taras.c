// Taras Beck, Merchant of Shadow
// Thorn@ShadowGate
// 4/9/96
// Town of Azha
// taras.c

#include <std.h>

inherit "/std/vendor";

create() {
   ::create();
   set_name("Taras Beck");
   set_id( ({ "taras", "beck", "merchant"}) );
   set_short("Taras Beck, Merchant from Shadow");
   set("aggressive", 0);
   set_level(19);
   set_long(
@AZHA
  You are looking at Taras Beck, a wealthy and prosperous merchant 
from the great city of Shadow, to the north.  He has come on behalf of
his family to survey the wares at this market and see if he cannot
make a few contacts along the way.  While no doubt a young man in
years, he has become very wise in the ways of trade, and sometimes
has things no one else can get....
AZHA
   );
   set_languages( ({ "common" }) );
   set_gender("male");
   set_alignment(2);
   set("race", "human");
   add_money("gold", random(500));
   set_body_type("human");
   set_property("no attack", 1);
   set_hd(19,3);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(500));
   set_max_mp(query_mp());
   set_storage_room("/d/azha/town/taras_storage.c");
   set_exp(0);
}
