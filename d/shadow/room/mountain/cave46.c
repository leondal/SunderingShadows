//cave46.c

#include <std.h>
#include "echoes.h"

inherit MINES;

void create(){
   ::create();
   set_exits(([
      "south" : ROOMS"cave42",
      "north" : ROOMS"cave47"
   ]));
}
