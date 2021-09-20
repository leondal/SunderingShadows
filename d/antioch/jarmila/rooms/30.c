
#include <std.h>
#include "../jarmila.h"
inherit STORAGE"hill.c";

void create(){
   ::create();
   set_exits(([
      "south" : ROOMS"29",
      "northwest" : ROOMS"31",
   ]));
}

