#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit CANALBANK_BASE;


void create() {
  ::create();
  swing_dest =  "broken_bridge01";
  blockdir ="west";


  add_item( ({"bridge", "stone bridge", "broken bridge", "collapsed bridge"}), 
    "The stone built bridge has collapsed in the middle and no longer offers"
   +" a way across the"
   +" %^BOLD%^%^BLACK%^c%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^nal%^RESET%^. The"
   +" stones of its construction are of an impressive size and show a good"
   +" standard of workmanship, but the design is rather unusual.");

  add_item( ({ "break", "break in the jungle", "break in the jungle foliage"}), 
    "The %^ORANGE%^ancient road%^RESET%^ has been largely overgrown by the"
   +" %^GREEN%^j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^ORANGE%^l%^GREEN%^e"
   +"%^RESET%^. Only patches of stone remain, green with %^GREEN%^moss%^RESET%^"
   +" and crossed over with %^ORANGE%^tree roots%^RESET%^. Even so, what is"
   +" left suggests that long ago this may have been a major causeway.");


  set_exits( ([
	"northeast":CITY_ROOM+"city_jung04",
      "east":CITY_ROOM+"city_jung05",
      "south":CITY_ROOM+"ruin01"  ]) );
}


string long_desc(){
  return jung_desc() + "The remains of a %^RESET%^stone bridge%^GREEN%^ are"
   +" here, on the east bank of an %^BOLD%^%^BLACK%^abandoned"
   +" c%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^nal%^RESET%^%^GREEN%^. The canal runs"
   +" north-south, blocking travel to the west. The"
   +" j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^ORANGE%^l%^GREEN%^e presses in"
   +" all around, plants and trees surrounding the %^RESET%^bridge%^GREEN%^ and"
   +" the remaining stones of the %^ORANGE%^causeway%^GREEN%^. To the north and"
   +" south, you can make out the ruins of a small path running north to south,"
   +" and a number of %^RESET%^stone huts%^GREEN%^.";
}