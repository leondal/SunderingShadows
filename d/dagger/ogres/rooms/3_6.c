#include <std.h>
#include "../ogres.h"

inherit STORAGE"3rd.c";

void create(){
   ::create();
   set_exits(([
      "northwest" : ROOMS"3_5",
      "east" : ROOMS"3_7",
      "south" : ROOMS"3_8",
   ]));

}
