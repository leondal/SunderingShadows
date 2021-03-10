#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit RUIN_BASE;


void create() {
  ::create();
  pathdir = "north"; 
  add_item( ({"structure", "stone structure", 
    "different stone structure", "different sort of stone structure"}),
    "The structure to the east rises out of the"
   +" %^GREEN%^j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^ORANGE%^l%^GREEN%^e"
   +" floor%^RESET%^, to a height of perhaps two metres. It seems to be in"
   +" ruins, but what you can make out through the jungle looks like it"
   +" might have been a bridge.");

  set_exits(([
     "north" : CITY_ROOM + "canalbank04",
      "east" : CITY_ROOM + "city_jung08"
   ]));
}

string long_desc(){
  return ::long_desc() + "To the north, you can make out the ruins"
   +" of a different sort of stone structure.";

}
