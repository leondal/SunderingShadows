#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit CANALBANK_BASE;


void create() {
  ::create();
  swing_dest = "canalbank01";
  blockdir ="west";


  add_item( ({"hut", "huts", "stone hut", "stone huts", "ruin", "ruins"}), 
    "The ruins are mostly obscured by the %^GREEN%^j%^BOLD%^%^GREEN%^u"
   +"%^RESET%^%^GREEN%^ng%^ORANGE%^l%^GREEN%^e f%^BOLD%^%^GREEN%^o"
   +"%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^a%^ORANGE%^g"
   +"%^GREEN%^e%^RESET%^, but you can see that there are a number of them to"
   +" your west. You think there might be one that is still intact, but you"
   +" will have to get closer to get a better look.");
  add_item( ({"path", "small path"}), "The %^ORANGE%^path%^RESET%^ you can"
   +" see to the south is very %^GREEN%^overgrown%^RESET%^, but a few stones"
   +" are still visible on the ground.");

  add_item( ({ "break", "break in the jungle", "break in the jungle foliage"}), 
    "To the west of the ruins of the %^ORANGE%^path%^RESET%^ and scattered"
   +" huts to the south, and continuing further south, the %^GREEN%^j"
   +"%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^ORANGE%^l%^GREEN%^e"
   +" f%^BOLD%^%^GREEN%^o%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^i"
   +"%^RESET%^%^GREEN%^a%^ORANGE%^g%^GREEN%^e%^RESET%^ seems to break in a"
   +" line. You can't make out why from here.");


  set_exits( ([
	"northeast":JCITY+"rooms/city_jung03",
      "southeast":JCITY+"rooms/city_jung04",
          "south":JCITY + "rooms/hut02"
    ]) );
}


string long_desc(){
  return ::long_desc() + "To the south, you can make out the ruins of a small"
  +" %^ORANGE%^path%^GREEN%^ heading further south, and a number of"
  +" %^RESET%^stone huts%^GREEN%^. There also appears to be a break in the"
  +" j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^ORANGE%^l%^GREEN%^e"
  +" f%^BOLD%^%^GREEN%^o%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^i"
  +"%^RESET%^%^GREEN%^a%^ORANGE%^g%^GREEN%^e in the same direction.";

}
