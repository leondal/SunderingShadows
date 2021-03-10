#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit GRAND_HUT_BASE;


void create() {
  ::create();
  av_dir = "north-south"; 

  set_exits(([
     "north" : CITY_ROOM + "city_jung11",
 "northwest" : CITY_ROOM + "city_jung12",
     "enter" : CITY_ROOM + "grand_interior02",
     "south" : CITY_ROOM + "ragged_road03"
   ]));
}

