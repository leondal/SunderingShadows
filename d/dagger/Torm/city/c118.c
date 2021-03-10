#include <std.h>
#include "../tormdefs.h"
inherit BATH;
void create(){
  ::create();
  set_exits(([
  "north":TCITY+"c115",
  "east":TCITY+"c113",
  "west":TCITY+"c117",
  "south":TCITY+"c120",
  ]));
}
