//a16.c

#include <std.h>
#include "../tharis.h"

inherit ALLEY;

void create(){
   ::create();
   set_exits(([
      "north":ROOMS"a15",
      "south":ROOMS"a17",
   ]));
}
