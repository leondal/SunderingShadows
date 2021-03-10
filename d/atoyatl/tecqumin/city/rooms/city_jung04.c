#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit TECBASE + "jung_base.c";

void create() {
  ::create();
  add_item( ({"road", "ancient road", "remains of road", "remains of ancient road"}), 
    "The ancient road has been largely overgrown by the"
   +" %^GREEN%^j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^ORANGE%^l%^GREEN%^e%^RESET%^."
   +" Only patches of stone remain, green with %^GREEN%^moss%^RESET%^ and crossed"
   +" over with %^ORANGE%^tree roots%^RESET%^. Even so, what is left suggests that"
   +" long ago this may have been a major causeway.");

  add_item( ({"hut", "huts", "stone hut", "stone huts", "ruin", "ruins", "ruined hut", 
        "ruined huts", "ruined stone hut", "ruined stone huts"}), 
    "The ruins are mostly obscured by the"
   +" %^GREEN%^j$%BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^ORANGE%^l%^GREEN%^e"
   +" f%^BOLD%^%^GREEN%^o%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^a"
   +"%^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^e, but you can see that there are a number"
   +" of them to your west. You will have to get closer to get a better look.");

  set_exits(([
      "northwest" : CITY_ROOM + "canalbank02",
      "northeast" : CITY_ROOM + "ruin03", 
      "southwest" : CITY_ROOM + "broken_bridge02",
      "south" : CITY_ROOM + "city_jung05",
      "southeast" : CITY_ROOM + "ragged_road02"
   ]));
}



string long_desc(){
  return ::base_desc() + " To the southeast, the"
  +" j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^ORANGE%^l%^GREEN%^e opens"
  +" slightly, and you can make out what looks like the remains of an%^RESET%^"
  +" ancient road%^GREEN%^ running east to west. To the northeast, you can make"
  +" out the ruins of a number of %^RESET%^stone huts%^GREEN%^.";

}
