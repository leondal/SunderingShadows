#include <std.h>
#include "../ogres.h"

inherit STORAGE"2nd.c";

void create(){
   ::create();
   set_exits(([
      "south" : ROOMS"2_17",
      "west" : ROOMS"2_15",
   ]));

}

//lever goes here
