//cave47.c

#include <std.h>
#include "echoes.h"

inherit MINES;

void create(){
   ::create();
   set_exits(([
      "west" : ROOMS"cave48",
      "south" : ROOMS"cave46"
   ]));
}
