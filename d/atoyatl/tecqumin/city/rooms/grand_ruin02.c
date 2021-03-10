#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit GRAND_RUIN_BASE;

void create() {
  ::create();
  av_dir = "to the east";
  set_exits(([
      "west" : JCITY + "rooms/grand_hut01"
   ]));
}

string long_desc(){
  return ::base_desc();
}
