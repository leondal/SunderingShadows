#include <std.h>
#include "../ogres.h"

inherit STORAGE"2nd.c";

void create(){
   ::create();
   set_exits(([
      "southwest" : ROOMS"2_25",
      "north" : ROOMS"2_23",
   ]));

}

//lever goes here
