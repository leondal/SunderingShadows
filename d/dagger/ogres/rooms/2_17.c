#include <std.h>
#include "../ogres.h"

inherit STORAGE"2nd.c";

void create(){
   ::create();
   set_exits(([
      "north" : ROOMS"2_16",
      "southeast" : ROOMS"2_18",
   ]));

}

//lever goes here
