#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit GRAND_HUT_BASE;


void create() {
  ::create();
  av_dir = "to the south and to the east"; 

  set_exits(([
     "south" : JCITY + "rooms/clear_road01",
     "east"  : JCITY + "rooms/grand_ruin02",
     "enter" : JCITY + "rooms/grand_interior01"
   ]));
}
