#include <std.h>
#include "../tharis.h"
inherit STORAGE"sewer";

void create(){
   ::create();
   set_long(::query_long()+"There is a hole with ladder leading down.%^RESET%^\n");
   set_exits(([
      "up" : ROOMS"wall27",
      "south" : SEWERS"sewer14",
      "down":"/d/shadow/ratpaths/rooms/rp_p023_n010",
   ]));
}
