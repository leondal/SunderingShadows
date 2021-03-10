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
   +" over with %^ORANGE%^tree roots%^GREEN%^. Even so, what is left suggests that"
   +" long ago this may have been a major causeway.");

  add_item( ({"stone", "structure", "stone structure"}), 
    "The structure to the east rises out of the"
   +" %^GREEN%^j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^ORANGE%^l%^GREEN%^e floor"
   +"%^RESET%^, to a height of perhaps two metres. It seems to be in ruins, but what"
   +" you can make out through the jungle looks like it might have been a bridge.");

  set_exits(([
      "north" : CITY_ROOM + "city_jung04",
      "south" : CITY_ROOM + "city_jung06", 
      "west" : CITY_ROOM + "broken_bridge02",
      "east" : CITY_ROOM + "ragged_road02"
   ]));
}



string long_desc(){
  return ::base_desc() + " To the west, you can make out the ruins of a %^RESET%^stone"
  +" structure%^GREEN%^. To the east, the"
  +" j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^ORANGE%^l%^GREEN%^e opens slightly, and"
  +" you can make out what looks like the remains of an %^ORANGE%^ancient road"
  +" %^GREEN%^heading east.";

}
