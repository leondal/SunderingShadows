//a13.c

#include <std.h>
#include "../tharis.h"

inherit ALLEY;

void create(){
   ::create();
   set_exits(([
      "south":ROOMS"a14",
      "northwest":ROOMS"a12",
   ]));
}
