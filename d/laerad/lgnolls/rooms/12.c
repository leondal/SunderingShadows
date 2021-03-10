#include <std.h>
#include "../lgnoll.h"

inherit STORAGE"common_ground.c";

void create(){
   ::create();
   set_exits(([
      "east" : ROOMS"6",
      "west" : ROOMS"13",
   ]));

}