#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit BRIDGEBASE;


void create() {
  bridge_dir = "west";
  ::create();
  set_exits(([
     "east" : CITY_ROOM + "clear_road01",
     "west" : CITY_ROOM + "bridge01"
   ]));
}


