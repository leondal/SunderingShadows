#include <std.h>
#include "../ogres.h"

inherit STORAGE"3rd.c";

void create(){
   ::create();
   set_exits(([
      "south" : ROOMS"3_2",
      "north" : ROOMS"3_d",
   ]));

}
