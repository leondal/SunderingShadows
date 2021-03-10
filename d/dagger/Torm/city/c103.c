#include <std.h>
#include "../tormdefs.h"
inherit PARK;
void create(){
  ::create();
  set_exits(([
  "north":TCITY+"c111",
  "east":TCITY+"c104",
  "west":TCITY+"c110",
  "south":TCITY+"c45",
  ]));
}
