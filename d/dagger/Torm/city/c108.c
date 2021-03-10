#include <std.h>
#include "../tormdefs.h"
inherit PARK;
void create(){
  ::create();
  set_exits(([
  "east":TCITY+"c107",
  "south":TCITY+"c109",
  ]));
}
