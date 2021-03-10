#include <std.h>
#include "../ogres.h"

inherit STORAGE"3rd.c";

void create(){
   ::create();
   set_exits(([
      "east" : ROOMS"3_10",
      "west" : ROOMS"3_3",
   ]));

}
