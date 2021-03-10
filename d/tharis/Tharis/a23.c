//a23.c

#include <std.h>
#include "../tharis.h"

inherit ALLEY;

void create(){
   ::create();
   set_exits(([
      "west":ROOMS"a24",
      "north":ROOMS"a22",
   ]));
}
