#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit TECBASE + "jung_base.c";


void create() {
  ::create();

  add_item( ({"hut", "stone hut", "large stone hut", "large hut" }),
     "The large stone hut to the south is mostly intact. It is much larger"
    +" and grander in design than the smaller huts to be found further west"
    +" in the jungle.");

  add_item( ({"ruin", "ruined hut", "similar building" }),
     "To the north is the partially collapsed ruin of a circular building."
    +" Not much is left standing, but the quantity of stone suggests a much"
    +" grander  building than the stone huts to be found further west in the"
    +" jungle");

  set_exits(([
      "north" : CITY_ROOM + "grand_ruin03",
      "south" : CITY_ROOM + "grand_hut02",
      "west" : CITY_ROOM + "city_jung12"
   ]));
}

string long_desc(){
  return ::base_desc() + "To the south, the" 
   +" %^GREEN%^j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^ORANGE%^l%^GREEN%^e"
   +" opens out on a %^RESET%^large stone hut%^GREEN%^, which appears to be"
   +" mostly intact. To the north is the ruin of another%^RESET%^ similar"
   +" building.";
}
