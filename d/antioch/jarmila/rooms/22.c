
#include <std.h>
#include "../jarmila.h"
inherit STORAGE"hill.c";

void create(){
   ::create();
   set_exits(([
      "southeast" : ROOMS"19",
      "west" : ROOMS"23",
   ]));
}

