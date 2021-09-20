#include <std.h>
#include "../jarmila.h"
inherit STORAGE"hill.c";

void create(){
   ::create();
   set_exits(([
      "northeast" : ROOMS"14",
      "south" : ROOMS"13",

   ]));
}
