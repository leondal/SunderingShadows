#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit R_ROAD_BASE;


void create() {
  ::create();
  add_item( ({ "bridge", "stone bridge"}), "The bridge is of fairly"
  +" simple design. A small flight of steps leads from the causeway"
  +" up to the stone walkway");
  set_exits(([ 
      "east" : CITY_ROOM + "bridge01",
      "west" : CITY_ROOM + "city_jung05",
      "north": CITY_ROOM + "ruin04",
      "northwest": CITY_ROOM + "city_jung04",
      "south": CITY_ROOM + "city_jung09"
   ]));
}


string short_desc(){
  return "%^BOLD%^%^GREEN%^In a %^RESET%^%^GREEN%^thick%^BOLD%^"
           +" %^GREEN%^jungle";
}


string long_desc(){

return base_desc() + "Here and there, the jungle floor opens up revealing"
  +" patches of worked %^RESET%^gray stone%^GREEN%^, apparently the remains"
  +" of an %^RESET%^ancient road %^GREEN%^heading east to west. The road"
  +" seems to lead toward a%^RESET%^" 
 +" stone bridge%^GREEN%^ to the east. To the west, it fades back into"
 +" the j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ngle.";

}
