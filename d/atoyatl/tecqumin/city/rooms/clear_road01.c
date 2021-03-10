#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit C_ROAD_BASE;


void create() {
  ::create();
  add_item( ({ "stone", "structure", "stone structure", "larger stone 
                                                        structure"}),
  "The structure to the east rises out of the jungle floor, to a"
 +" height of perhaps two metres. It seems to be in ruins, but what"
 +" you can make out through the jungle looks like it might have been"
 +" a bridge.");
  set_exits(([ 
      "west" : CITY_ROOM + "bridge02",
      "east" : CITY_ROOM + "plaza",
     "south" : CITY_ROOM + "grand_ruin01",
     "north" : CITY_ROOM + "grand_hut01"
   ]));
}


string short_desc(){
  return "%^BOLD%^%^GREEN%^In a %^RESET%^%^GREEN%^thick%^BOLD%^"
           +" %^GREEN%^jungle";
}


string long_desc(){

return ::base_desc() + "%^RESET%^ A broad stone causeway runs east-west through the jungle here. To the east, it leads to a stone bridge across the canal. To the west, it opens out to a large stone plaza.";

}
