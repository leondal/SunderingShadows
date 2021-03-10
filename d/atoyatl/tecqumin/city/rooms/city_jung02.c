#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit TECBASE + "jung_base.c";


void create() {
  ::create();
  add_item( ({"road", "ancient road", "remains of road", 
                                  "remains of ancient road"}), 
   "The ancient road has been largely overgrown by the"
  +" %^GREEN%^j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^ORANGE%^"
  +"l%^GREEN%^e%^RESET%^. Only patches of stone remain, green"
  +" with moss and crossed over with tree roots. Even so, what"
  +" is left suggests that long ago this may have been a major"
  +" causeway." );
  set_exits(([ 
      "south" : CITY_ROOM + "ragged_road01",
      "northeast" : CITY_ROOM + "canalbank01"
   ]));
}


string short_desc(){
  return "%^BOLD%^%^GREEN%^In a %^RESET%^%^GREEN%^thick%^BOLD%^"
           +" %^GREEN%^jungle";
}


string long_desc(){

return base_desc() + " To the south, the %^GREEN%^j"
  +"%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^ORANGE%^l%^GREEN%^e"
  +" opens slightly, and you can make out what looks like the"
  +" remains of an %^RESET%^ancient road%^GREEN%^ running east"
  +" to west.";

}
