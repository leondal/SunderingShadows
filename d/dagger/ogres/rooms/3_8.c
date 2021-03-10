#include <std.h>
#include "../ogres.h"

inherit STORAGE"3rd.c";

void create(){
   ::create();
   set_exits(([
      "west" : ROOMS"3_c",
      "north" : ROOMS"3_6",
   ]));

}
