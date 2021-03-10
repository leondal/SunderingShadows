
#include <std.h>
#include "../ogres.h"

inherit STORAGE"3rd.c";

void create(){
   ::create();
   set_exits(([
       "south" : ROOMS"ogremaze15",
       "north" : ROOMS"ogremaze13",

   ]));

}