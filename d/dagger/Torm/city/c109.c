#include <std.h>
#include "../tormdefs.h"
inherit PARK;
void create(){
  ::create();
  set_exits(([
  "north":TCITY+"c108",
  "south":TCITY+"c110",
  "garden":"/d/magic/temples/sune"
  ]));
}
