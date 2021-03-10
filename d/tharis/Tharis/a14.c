//a14.c

#include <std.h>
#include "../tharis.h"

inherit ALLEY;

void create(){
   ::create();
   set_exits(([
      "north":ROOMS"a13",
      "east":ROOMS"a15",
   ]));
}
