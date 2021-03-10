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

  add_item( ({"palace", "", "palatial structure", "large building"}), 
    "You can't see much from here, but the building is made of stone, and is"
   +" impressively large in scale.");

  set_exits(([
      "southeast" : CITY_ROOM + "grand_hut02",
      "east" : CITY_ROOM + "city_jung11"
   ]));
}

string long_desc(){
  return ::base_desc() + "To the southeast, the" 
   +" %^GREEN%^j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^ORANGE%^l%^GREEN%^e"
   +" opens out on a %^RESET%^large stone hut%^GREEN%^, which appears to be"
   +" mostly intact. To the west and northwest, the top of a palatial"
    +" structure can be made out above the treetops.";
}
