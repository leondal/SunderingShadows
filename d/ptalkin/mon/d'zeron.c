#include <std.h>
inherit "/std/vendor";

create() {
   ::create();
set_name("D'zeron");
set_id(({"D'zeron", "d'zeron", "shop keeper", "shopkeeper"}));
set_short("D'zeron, shopkeeper");
set_long("%^GREEN%^D'zeron awaits behind her counter filled with urns of flowers and boxes of chocolates.  D'zeron is a beautiful elf, golden haired, tawny eyed, and very, very shapely.  She wears a tunic of soft summer green, with a matching long embroidered skirt.  Her ready smile greets you as you look around.");
   set("aggressive", 0);
   set_level(19);
set_gender("female");
   set_alignment(4);
set("race", "elf");
set_size(2);
   add_money("gold", random(500));
   set_body_type("human");
   set_property("no attack", 1);
   set_hd(19,3);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(500));
   set_max_mp(query_mp());
//
// special functions for the shops
//
//      where the items for sale/ or are bought are stored.
	set_storage_room("/d/ptalkin/room/f_storage");
// 	Type of items allowed in this store.
//	Valid types: misc
	set_items_allowed("misc");
}

