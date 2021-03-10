#include <std.h>
#include "../tormdefs.h"
inherit TOWER;
void create()
  {
  ::create();
  set_exits(([
  "down":TCITY+"c79",
  ]));
}
