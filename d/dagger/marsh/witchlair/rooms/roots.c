#include <std.h>
#include "../witchlair.h"
inherit BASE"root_inherit.c";

void create(){
   ::create();
   set_exits(([
     "north":ROOMS"roots2.c",
     "up":ROOMS"grove6.c",
   ]));
}
