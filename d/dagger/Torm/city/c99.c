#include <std.h>
#include "../tormdefs.h"
inherit FORTRESS;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
  set_exits(([
  "southwest":TCITY+"c77",
  ]));
}
