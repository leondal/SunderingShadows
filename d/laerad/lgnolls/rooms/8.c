#include <std.h>
#include "../lgnoll.h"

inherit STORAGE"common_ground.c";

void create(){
   ::create();
   set_exits(([
      "west" : ROOMS"7",
      "north" : ROOMS"9",
   ]));

}