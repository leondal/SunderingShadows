#include <std.h>
#include "../tormdefs.h"
inherit BOARDWALK;
void create()
  {
  ::create();
  set_exits(([
  "east":TCITY+"c69",
  "west":TCITY+"c67",
  ]));
}
