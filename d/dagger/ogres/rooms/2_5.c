#include <std.h>
#include "../ogres.h"

inherit STORAGE"2nd.c";

void create(){
   ::create();
   set_exits(([
      "north" : ROOMS"2_6",
      "southwest" : ROOMS"2_4",
   ]));

}