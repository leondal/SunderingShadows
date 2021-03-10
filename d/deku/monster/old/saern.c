#include <std.h>

inherit "/std/vendor";

void create() {
   ::create();
   set_name("Shop Keeper");
   set_id( ({ "clerk", "saern", "shopkeeper"}) );
   set_short("Saern, Weapon Store clerk");
   set("aggressive", 0);
   set_level(10);
   set_long("He buys and sells weapons.\n"+
	"<help shop> will get you a list of shop commands.\n");
   set_gender("male");
   set_alignment(4);
   set("race", "human");
    set_class("fighter");
   set_body_type("human");
   set_storage_room("/d/deku/new/w_storage");
   set_hd(10,3);
   set_exp(10);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(0);
   set_max_mp(query_mp());
   set_property("generic db", 1);
   set_items_allowed("weapon");
}
