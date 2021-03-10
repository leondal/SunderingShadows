#include <std.h>
#include "../ogres.h"

inherit STORAGE"3rd.c";

void create(){
   ::create();
   set_exits(([
      "north" : ROOMS"3_3",
      "west" : ROOMS"3_6",
   ]));

}
