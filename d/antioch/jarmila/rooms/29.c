
#include <std.h>
#include "../jarmila.h"
inherit STORAGE"hill.c";

void create(){
   ::create();
   set_exits(([
      "southwest" : ROOMS"28",
      "north" : ROOMS"30",
   ]));
}

