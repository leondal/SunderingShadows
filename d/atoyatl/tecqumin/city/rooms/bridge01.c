#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit BRIDGEBASE;


void create() {
  bridge_dir = "east";
  ::create();
  set_exits(([
     "east" : CITY_ROOM + "bridge02",
     "west" : CITY_ROOM + "ragged_road02"
   ]));
}


