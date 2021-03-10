#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit C_ROAD_BASE;


void create() {
  ::create();
  set_exits(([ 
      "west" : CITY_ROOM + "plaza",
      "south" : CITY_ROOM + "city_jung10.c", 
      "east" : CITY_ROOM + "ragged_road03"
   ]));
}


string short_desc(){
  return "%^BOLD%^%^GREEN%^In a %^RESET%^%^GREEN%^thick%^BOLD%^"
           +" %^GREEN%^jungle";
}


string long_desc(){

return ::base_desc() + "%^RESET%^ A broad stone causeway %^GREEN%^"
  +"runs east-west through the jungle here. To the east, it peters"
  +" into ruin. To the west, it opens out to a %^RESET%^large stone"
  +" plaza%^GREEN%^.";

}
