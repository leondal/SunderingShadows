#include <std.h>
#include "../tharis.h"

inherit STORAGE"wall.c";

void create(){
   ::create();
   set_exits(([
      "west" : ROOMS"wall9",
      "south" : ROOMS"wall17",
   ]));

}