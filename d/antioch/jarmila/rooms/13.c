#include <std.h>
#include "../jarmila.h"
inherit STORAGE"military.c";

void create(){
   ::create();
   set_exits(([
      "north" : ROOMS"trail1",
      "south" : ROOMS"12",

   ]));
}
