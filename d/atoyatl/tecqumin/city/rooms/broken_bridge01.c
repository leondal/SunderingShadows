#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit CANALBANK_BASE;


void create() {
  ::create();
  swing_dest = "broken_bridge02";
  blockdir ="east";


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
	"west":CITY_ROOM+"ragged_road01"  ]) );
}


string long_desc(){
  return jung_desc() + "The remains of the ancient %^ORANGE%^causeway"
    +" %^GREEN%^arrive at the remains of a%^RESET%^ stone bridge%^GREEN%^"
    +" on the west bank of an %^BOLD%^%^BLACK%^abandoned canal"
    +"%^RESET%^%^GREEN%^. The canal runs north-south, blocking further travel"
    +" to the east. The j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^ORANGE%^l"
    +"%^GREEN%^e presses in all around, plants and trees surrounding the"
    +" %^RESET%^bridge %^GREEN%^and the remaining stones of the causeway.";
}