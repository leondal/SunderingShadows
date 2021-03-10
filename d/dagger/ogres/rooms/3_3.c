#include <std.h>
#include "../ogres.h"

inherit STORAGE"3rd.c";

void create(){
   ::create();
   set_exits(([
      "northwest" : ROOMS"3_4",
      "north" : ROOMS"3_2",
      "east" : ROOMS"3_9",
      "south" : ROOMS"3_7",
   ]));

}
