#include <std.h>
#include "../ogres.h"

inherit STORAGE"2nd.c";

void create(){
   ::create();
   set_exits(([
      "east" : ROOMS"2_15",
      "west" : ROOMS"2_1",
   ]));

}

//lever goes here
