
#include <std.h>
#include "../jarmila.h"
inherit STORAGE"hill.c";

void create(){
   ::create();
   set_exits(([
      "west" : ROOMS"27",
      "northeast" : ROOMS"29",
   ]));
}

