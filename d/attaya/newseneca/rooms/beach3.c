//beach3.c - ~Circe~ 6/13/08 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit STORAGE"beach";

void create(){
   ::create();
   set_long(::query_long()+"A %^ORANGE%^stairway %^RESET%^carved "+
      "from the bedrock lends access to the pathway that leads "+
      "back up to the city.\n");
   set_exits(([
      "north" : ROOMS"rockypath13",
      "west" : ROOMS"beach2",
      "east" : ROOMS"beach4",
      "southwest" : ROOMS"beach7",
      "south" : ROOMS"beach8",
      "southeast" : ROOMS"beach9"
   ]));
   add_item("stairway","The stairs are carved straight from the "+
      "bedrock and extend outward onto the beach.  A simple "+
      "%^ORANGE%^wooden handrail %^RESET%^has been attached "+
      "to each side, offering support for those who climb.");
}