#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit TECBASE + "jung_base.c";


void create() {
  ::create();

  add_item( ({"road", "ancient road", "remains off ancient road"}), 
    "The ancient road has been largely overgrown by the"
   +" %^GREEN%^j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^ORANGE%^l%^GREEN%^e"
   +" Only patches of stone remain, green with %^GREEN%^moss%^RESET%^ and"
   +" crossed over with %^ORANGE%^tree roots%^RESET%^. Even so, what is left"
   +" suggests that long ago this may have been a major causeway.");

  set_exits(([
     "north" : CITY_ROOM + "ragged_road02",
      "west" : CITY_ROOM + "city_jung06",
  "southwest": CITY_ROOM + "city_jung07"
   ]));
}

string long_desc(){
  return ::base_desc() + "To the north, the"
    +" %^GREEN%^j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ngle %^RESET%^opens slightly,"
    +" and you can make out what looks like the remains of an %^ORANGE%^ancient"
    +" road%^RESET%^ running east to west.";
}
