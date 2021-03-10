//a21.c

#include <std.h>
#include "../tharis.h"

inherit ALLEY;

void create(){
   ::create();
   set_exits(([
      "east":ROOMS"a20",
      "south":ROOMS"a22",
   ]));
}
