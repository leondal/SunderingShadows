#include <std.h>
#include "../tharis.h"

inherit STORAGE"wall.c";

void create(){
   ::create();
   set_exits(([
      "east" : ROOMS"wall5",
      "west" : ROOMS"wall3",
   ]));

}