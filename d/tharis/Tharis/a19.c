//a19.c

#include <std.h>
#include "../tharis.h"

inherit ALLEY;

void create(){
   ::create();
   set_exits(([
      "east":ROOMS"a17",
      "north":ROOMS"a20",
   ]));
}
