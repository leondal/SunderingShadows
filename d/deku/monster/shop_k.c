#include <std.h>

inherit "/std/vendor";

void create() {
   ::create();
   set_name("Shop Keeper");
   set_id( ({ "clerk", "dentiata", "shopkeeper"}) );
   set_short("%^YELLOW%^D%^RESET%^%^ORANGE%^entiata%^BLUE%^, %^BOLD%^W%^RESET%^%^BLUE%^eapon %^BOLD%^S%^RESET%^%^BLUE%^tore %^BOLD%^clerk%^WHITE%^");
   set("aggressive", 0);
   set_level(19);
     set_long("She buys and sells weapons.\n"+
	"<help shop> will get you a list of shop commands.\n");
   set_gender("female");
   set_alignment(4);
   set("race", "half-elf");
    set_class("fighter");
   set_body_type("human");
   set_storage_room("/d/deku/town/w_storage");
   set_hd(19,3);
   set_exp(10);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(0);
   set_max_mp(query_mp());
   set_items_allowed("weapon");
   remove_std_db();
   remove_dbs( ({"/d/db/vendor","/d/db/weapons"}) );
}

