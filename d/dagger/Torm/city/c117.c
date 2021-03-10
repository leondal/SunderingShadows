#include <std.h>
#include "../tormdefs.h"
inherit BATH;
void create(){
  ::create();
  set_exits(([
  "east":TCITY+"c118",
  "south":TCITY+"c119",
  ]));
}
