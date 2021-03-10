//a20.c

#include <std.h>
#include "../tharis.h"

inherit ALLEY;

void create(){
   ::create();
   set_exits(([
      "south":ROOMS"a19",
      "west":ROOMS"a21",
   ]));
}
