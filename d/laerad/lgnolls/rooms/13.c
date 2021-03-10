#include <std.h>
#include "../lgnoll.h"

inherit STORAGE"common_ground.c";

void create(){
   ::create();
   set_exits(([
      "east" : ROOMS"12",
      "north" : ROOMS"14",
   ]));

}