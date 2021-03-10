//a12.c

#include <std.h>
#include "../tharis.h"

inherit ALLEY;

void create(){
   ::create();
   set_exits(([
      "northeast":ROOMS"a11",
      "southeast":ROOMS"a13",
      "west":ROOMS"a10",
   ]));
}
