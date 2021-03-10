
#include <std.h>
#include "../ogres.h"

inherit STORAGE"3rd.c";

void create(){
   ::create();
   set_exits(([
       "north" : ROOMS"ogremaze10",
       "northwest" : ROOMS"ogremaze9",
       "northeast" : ROOMS"ogremaze11",

   ]));

}