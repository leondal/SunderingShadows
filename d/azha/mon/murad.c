// Murad as-Suleymen, Merchant from Verhedin City
// Thorn@ShadowGate
// 4/9/96
// Town of Azha
// murad.c

#include <std.h>

inherit "/std/vendor";

create() {
   ::create();
   set_name("as-Suleymen");
   set_id( ({ "murad", "assuleymen", "merchant"}) );
   set_short("Murad as-Suleymen, Merchant of Verhedin");
   set("aggressive", 0);
   set_level(19);
   set_long(
@AZHA
This wizened old man is Murad as-Suleymen, one of the most 
respected merchants from Verhedin Province, to the south.  He deals
throughout the Empire and is always seeking to open new markets. 
Azha seems to have finally warranted a look from him, and it appears
that he sees a profit to be made in this rough frontier town, or
perhaps, he knows of its past, and what it could be once again....
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
   set_storage_room("/d/azha/town/murad_storage.c");
   set_exp(0);
}
