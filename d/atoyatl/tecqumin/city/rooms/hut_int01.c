#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit HUT_INT_BASE;


void create() {
  ::create();
  set_exits(([
     "out" : CITY_ROOM + "hut01"
   ]));
}


