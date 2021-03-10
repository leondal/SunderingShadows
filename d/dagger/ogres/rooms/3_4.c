#include <std.h>
#include "../ogres.h"

inherit STORAGE"3rd.c";

void create(){
   ::create();
   set_exits(([
      "northwest" : ROOMS"3_a",
      "southeast" : ROOMS"3_3",
   ]));

}
