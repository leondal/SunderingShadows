//a15.c

#include <std.h>
#include "../tharis.h"

inherit ALLEY;

void create(){
   ::create();
   set_exits(([
      "west":ROOMS"a14",
      "south":ROOMS"a16",
   ]));
}
