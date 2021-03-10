#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit GRAND_RUIN_BASE;

void create() {
  ::create();
  av_dir = "north-south";
  set_exits(([
      "south" : JCITY + "rooms/city_jung11",
      "west" : JCITY + "rooms/city_jung13"  
   ]));
}

string long_desc(){
  return ::base_desc();
}

