#include <std.h>
#include "../tormdefs.h"
inherit BOARDWALK;
void create()
  {
  ::create();
  set_exits(([
  "east":TCITY+"c49",
  "west":TCITY+"c47",
  ]));
}
