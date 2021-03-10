#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit HUT_BASE;


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

  set_exits(([
     "north" : CITY_ROOM + "ruin01",
     "south" : CITY_ROOM + "canalbank04",
     "hut" : CITY_ROOM + "hut_int01",
     "east" : CITY_ROOM + "city_jung07"
   ]));
}

string long_desc(){
  return ::long_desc() + " To the east, the way is blocked by a stagnant"
   +" %^BOLD%^%^BLACK%^c%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^nal%^RESET%^" 
   +" %^GREEN%^heading north-south.";

}
