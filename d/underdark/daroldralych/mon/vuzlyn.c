#include <std.h>
#include "../defs.h"
inherit "/std/vendor";

void make_me();

void create() {
   ::create();
   make_me();
   set("aggressive", 0);
   set_level(15);
   set_gender("male");
   set_alignment(9);
   set_race("drow");
   add_money("gold", random(200));
   set_body_type("human");
   set_storage_room(STORAGE"general");
   set_hd(20,10);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_exp(1);
   set_property("no bow",1);
}

void make_me() {
   switch(random(2)) {
      case 0:
	set_name("Vuzlyn");
	set_id(({ "shop clerk","shopkeeper","clerk","vuzlyn","gstore"}));
	set_short("%^RESET%^%^BLUE%^Vuzlyn Kirrefyrm, the shop clerk%^RESET%^");
	set_long("%^BLUE%^Vuzlyn is a slender drow with %^WHITE%^short-cropped hair%^BLUE%^, clad in plain but "
"well-kept garments.  He keeps a careful watch over the store here, and anyone that enters or leaves it.  A "
"%^ORANGE%^brooch %^BLUE%^is pinned to the front of his clothes, marked with the insignia of a noble house."
"%^RESET%^");
	break;
     case 1:
	set_name("Seldszar");
	set_id(({ "shop clerk","shopkeeper","clerk","seldszar","gstore"}));
	set_short("%^RESET%^%^BLUE%^Seldszar Kirrefyrm, the shop clerk%^RESET%^");
	set_long("%^BLUE%^Seldszar is a fairly average-looking drow, with %^WHITE%^shoulder-length hair%^BLUE%^ "
"and %^BOLD%^%^BLACK%^dark eyes%^RESET%^%^BLUE%^.  He keeps a careful watch over the store here, and anyone "
"that enters or leaves it.  A %^ORANGE%^brooch %^BLUE%^is pinned to the front of his clothes, marked with the "
"insignia of a noble house.%^RESET%^.");
	break;
   }
}
