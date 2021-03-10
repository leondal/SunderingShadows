#include <std.h>
#include "../tormdefs.h"
inherit TANARN;
void create()
  {
  ::create();
  set_exits(([
  "up":TCITY+"c6a",
  "east":TCITY+"c7",
  "west":TCITY+"c5",
  "south":TCITY+"portal",
  ]));
}
