#include <std.h>
#include "../lgnoll.h"

inherit STORAGE"common_ground.c";

void create(){
   ::create();
   set_exits(([
      "south" : ROOMS"13",
      "north" : ROOMS"15",
   ]));

}