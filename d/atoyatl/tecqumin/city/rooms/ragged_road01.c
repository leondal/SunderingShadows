#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit R_ROAD_BASE;


void create() {
  ::create();
  add_item( ({ "stone", "structure", "stone structure", "larger stone 
                                                        structure"}),
  "The structure to the east rises out of the jungle floor, to a"
 +" height of perhaps two metres. It seems to be in ruins, but what"
 +" you can make out through the jungle looks like it might have been"
 +" a bridge.");
  set_exits(([ 
      "west" : JUNG_ROOM2 + "city_entrance",
      "east" : CITY_ROOM + "broken_bridge01",
      "north": CITY_ROOM + "city_jung02",
      "south": CITY_ROOM + "city_jung01"
   ]));
}


string short_desc(){
  return "%^BOLD%^%^GREEN%^In a %^RESET%^%^GREEN%^thick%^BOLD%^"
           +" %^GREEN%^jungle";
}


string long_desc(){

return ::base_desc() + "Here and there, the jungle floor opens up revealing"
  +" patches of worked %^RESET%^gray stone%^GREEN%^, apparently the remains"
  +" of an %^RESET%^ancient road %^GREEN%^heading east to west. To the"
  +" east, it leads to a%^RESET%^ larger stone structure%^GREEN%^. To the"
  +" west, it fades back into the jungle.";

}
