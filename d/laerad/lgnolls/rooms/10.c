#include <std.h>
#include "../lgnoll.h"

inherit STORAGE"common_ground.c";

void create(){
   ::create();
   set_exits(([
      "north" : ROOMS"11",
      "south" : ROOMS"9",
   ]));

}