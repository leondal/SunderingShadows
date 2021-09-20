#include <std.h>
#include "../jarmila.h"
inherit STORAGE"military.c";

void create(){
   ::create();
   set_exits(([
      "north" : ROOMS"13",
      "southwest" : ROOMS"10",

   ]));
}
