#include <std.h>
#include "../tormdefs.h"
inherit BOARDWALK;
void create()
  {
  ::create();
  set_exits(([
  "east":TCITY+"c88",
  "south":TCITY+"c93",
  "west":TCITY+"c86",
  ]));
}
