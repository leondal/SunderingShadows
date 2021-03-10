
#include <std.h>
#include "../ogres.h"

inherit STORAGE"3rd.c";

void create(){
   ::create();
   set_exits(([
       "north" : ROOMS"ogremaze28",
       "south" : ROOMS"ogremaze26",
       "northeast" : ROOMS"ogremaze29",

   ]));

}