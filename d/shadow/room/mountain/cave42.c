//cave42.c

#include <std.h>
#include "echoes.h"

inherit MINES;

void create(){
   ::create();
   set_exits(([
      "east" : ROOMS"cave14",
      "north" : ROOMS"cave46",
      "south" : ROOMS"cave43"
   ]));
}
