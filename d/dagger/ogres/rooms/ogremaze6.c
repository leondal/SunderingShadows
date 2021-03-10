
#include <std.h>
#include "../ogres.h"

inherit STORAGE"3rd.c";

void create(){
   ::create();
   set_exits(([
       "north" : ROOMS"ogremaze12",
       "south" : ROOMS"ogremaze5",
       "east" : ROOMS"ogremaze15",
       "west" : ROOMS"ogremaze7",

   ]));

}