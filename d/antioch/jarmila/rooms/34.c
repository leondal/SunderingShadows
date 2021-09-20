
#include <std.h>
#include "../jarmila.h"
inherit STORAGE"hill.c";

void create(){
   ::create();
   set_exits(([
      "north" : ROOMS"33",
      "southeast" : ROOMS"35",
   ]));
}

