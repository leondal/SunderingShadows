//a22.c

#include <std.h>
#include "../tharis.h"

inherit ALLEY;

void create(){
   ::create();
   set_exits(([
      "north":ROOMS"a21",
      "south":ROOMS"a23",
   ]));
}
