#include <std.h>
#include "../tormdefs.h"
inherit PARK;
void create(){
  ::create();
  set_exits(([
  "north":TCITY+"c105",
  "west":TCITY+"c103",
  ]));
}
