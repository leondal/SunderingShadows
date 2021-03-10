#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit GRAND_RUIN_BASE;

void create() {
  ::create();
  av_dir = "to the north";
  set_exits(([
      "north" : JCITY + "rooms/clear_road01"
   ]));
}

string long_desc(){
  return ::base_desc() + " Further to the %^RESET%^north%^GREEN%^,"
  +" it joins a broad causeway running east-west through the"
  +" j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^ORANGE%^l%^GREEN%^e.";
}
