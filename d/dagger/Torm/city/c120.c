#include <std.h>
#include "../tormdefs.h"
inherit BATH;
void create(){
  ::create();
  set_exits(([
  "north":TCITY+"c118",
  "west":TCITY+"c119",
  ]));
}
