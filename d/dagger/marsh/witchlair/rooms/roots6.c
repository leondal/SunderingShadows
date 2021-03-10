#include <std.h>
#include "../witchlair.h"
inherit BASE"root_inherit.c";

void create(){
   ::create();
   set_exits(([
     "northwest":ROOMS"roots7.c",
     "north":ROOMS"roots2.c",
     "northeast":ROOMS"roots2.c",
     "south":ROOMS"roots.c",
   ]));
}
