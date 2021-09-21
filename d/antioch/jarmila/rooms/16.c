#include <std.h>
#include "../jarmila.h"
inherit STORAGE"hill.c";

void create(){
   ::create();
   set_exits(([
      "southwest" : ROOMS"15",
      "north" : ROOMS"17",

   ]));
}
