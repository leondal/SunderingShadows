//a17.c

#include <std.h>
#include "../tharis.h"

inherit ALLEY;

void create(){
   ::create();
   set_exits(([
      "north":ROOMS"a16",
      "west":ROOMS"a19",
      "east":ROOMS"a18",
   ]));
}
