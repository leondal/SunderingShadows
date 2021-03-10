#include <std.h>
#include "../ogres.h"

inherit STORAGE"2nd.c";

void create(){
   ::create();
   set_exits(([
      "south" : ROOMS"2_20",
      "north" : ROOMS"2_18",
   ]));

}

//lever goes here
