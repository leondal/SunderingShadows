#include <std.h>
#include "../tharis.h"

inherit STORAGE"wall.c";

void create(){
   ::create();
   set_exits(([
      "north" : ROOMS"wall10",
      "south" : ROOMS"wall18",
   ]));

}