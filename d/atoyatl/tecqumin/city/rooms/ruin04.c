#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit RUIN_BASE;


void create() {
  ::create();
  pathdir = "north-south"; 
  add_item( ({ "canal", "disused canal", "stagnant canal"}),
    "The canal looks as though it has been disused for many years."
  +" The %^BLUE%^water%^RESET%^ is thick with %^GREEN%^weeds%^RESET%^"
  +" and varies in shade from %^GREEN%^green%^RESET%^ to"
  +" %^BOLD%^%^BLACK%^black%^RESET%^. In places it looks more like"
  +" %^GREEN%^swamp%^RESET%^; only the remains of stone banks keep it"
  +" straight and confirm that it was deliberately constructed.");

  add_item( ({ "road", "ancient road", "remains of road", 
                                        "remains of ancient road"}),
    "The ancient road has been largely overgrown by the"
   +" %^GREEN%^j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^ORANGE%^l"
   +"%^GREEN%^e%^RESET%^. Only patches of stone remain, %^GREEN%^green"
   +" %^RESET%^with %^GREEN%^moss%^RESET%^ and crossed over with"
   +" %^ORANGE%^tree roots%^RESET%^. Even so, what is left suggests"
   +" that long ago this may have been a major causeway.");

  set_exits(([
     "north" : CITY_ROOM + "ruin03",
     "south" : CITY_ROOM + "ragged_road02"
   ]));
}

string long_desc(){
  return ::long_desc() + "To the east, the way is blocked by a stagnant"
  +" %^BOLD%^%^BLACK%^c%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^n%^RESET%^"
  +"%^GREEN%^a%^BOLD%^%^BLACK%^l%^RESET%^ heading north-south. To the"
  +" south, you can make out what looks like the remains of an"
  +" %^ORANGE%^ancient road%^RESET%^ running east to west.";

}
