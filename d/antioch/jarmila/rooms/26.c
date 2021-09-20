
#include <std.h>
#include "../jarmila.h"
inherit STORAGE"hill.c";

void create(){
   ::create();
   set_exits(([
      "north" : ROOMS"25",
      "southeast" : ROOMS"27",
   ]));
}

