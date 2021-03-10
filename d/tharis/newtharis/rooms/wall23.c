#include <std.h>
#include "../tharis.h"

inherit STORAGE"wall.c";

void create(){
   ::create();
   set_exits(([
      "east" : ROOMS"ngate2",
      "west" : ROOMS"wall24",
   ]));

}