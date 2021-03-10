#include <std.h>
#include "../tormdefs.h"
inherit PARK;
void create(){
  ::create();
  set_exits(([
  "south":TCITY+"c104",
  "north":TCITY+"c106",
  ]));
}
