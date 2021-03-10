#include <std.h>
#include "../piratedefs.h"
inherit "/std/vendor";

void create() {
   ::create();
   set_name("Tannora");
   set_id( ({"tannora","shopkeeper","shopkeep"}) );
   set_short("Tannora, owner of The Wide Open Port");
   set("aggressive", 0);
   set_level(15);
   set_long("This wiry, darkhaired human is one of the rare women in this village with a higher profession "
"than entertainment for the pirates.  She moves with obvious grace and balance, and constantly keeps watch "
"over the shop and everyone in it.  She looks quite capable of handling herself.");
   set_gender("female");
   set_alignment(6);
   set_race("human");
   add_money("gold", random(200));
   set_body_type("human");
   set_storage_room(STORAGE"general");
   set_hd(10,3);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_exp(1);
}
