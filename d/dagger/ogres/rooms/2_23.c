#include <std.h>
#include "../ogres.h"

inherit STORAGE"2nd.c";

void create(){
   ::create();
   set_exits(([
      "northwest" : ROOMS"2_1",
      "south" : ROOMS"2_24",
   ]));

}

//lever goes here
