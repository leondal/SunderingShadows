#include <std.h>
#include "../tormdefs.h"
inherit PARK;
void create(){
  ::create();
  set_exits(([
  "north":TCITY+"c109",
  "east":TCITY+"c103",
  ]));
}
