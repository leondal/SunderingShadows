#include <std.h>
#include "../ogres.h"

inherit STORAGE"3rd.c";

void create(){
   ::create();
   set_exits(([
      "south" : ROOMS"3_3",
      "north" : ROOMS"3_1",
   ]));

}
