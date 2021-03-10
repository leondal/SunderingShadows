#include <std.h>
#include "../tormdefs.h"
inherit TANARN;
void create()
  {
  ::create();
  set_exits(([
  "east":TCITY+"c8",
  "west":TCITY+"c6",
  "south":TCITY+"psion",
  ]));
}
