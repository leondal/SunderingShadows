#include <std.h>
#include "../jarmila.h"
inherit STORAGE"military.c";

void create(){
   ::create();
   set_exits(([

      "northeast" : ROOMS"12",
      "northwest" : ROOMS"11",
      "southeast" : ROOMS"9",

   ]));
}
