#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit RUIN_BASE;


void create() {
  ::create();
  pathdir = "south"; 
  add_item( ({ "canal", "disused canal", "stagnant canal"}),
    "The canal looks as though it has been disused for many years."
  +" The %^BLUE%^water%^RESET%^ is thick with %^GREEN%^weeds%^RESET%^"
  +" and varies in shade from %^GREEN%^green%^RESET%^ to"
  +" %^BOLD%^%^BLACK%^black%^RESET%^. In places it looks more like"
  +" %^GREEN%^swamp%^RESET%^; only the remains of stone banks keep it"
  +" straight and confirm that it was deliberately constructed.");

  set_exits(([
 "southwest" : CITY_ROOM + "city_jung04",
     "south" : CITY_ROOM + "ruin04"
   ]));
}

string long_desc(){
  return ::long_desc() + "To the east, the way is blocked by a stagnant"
  +" %^BOLD%^%^BLACK%^c%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^n%^RESET%^%^GREEN%^a"
  +"%^BOLD%^%^BLACK%^l%^RESET%^ heading north-south.";

}
