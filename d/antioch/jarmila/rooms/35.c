
#include <std.h>
#include "../jarmila.h"
inherit STORAGE"hill.c";

void create(){
   ::create();
   set_exits(([
      "northwest" : ROOMS"33",
      "east" : ROOMS"top",
   ]));
}

