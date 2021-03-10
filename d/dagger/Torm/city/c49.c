#include <std.h>
#include "../tormdefs.h"
inherit BOARDWALK;
void create()
  {
  ::create();
  set_exits(([
  "east":TCITY+"c50",
  "north":TCITY+"c37",
  "west":TCITY+"c48",
  ]));
}
