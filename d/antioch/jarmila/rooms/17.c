
#include <std.h>
#include "../jarmila.h"
inherit STORAGE"hill.c";

void create(){
   ::create();
   set_exits(([
      "south" : ROOMS"16",
      "north" : ROOMS"18",

   ]));
}

