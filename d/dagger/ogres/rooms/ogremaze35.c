
#include <std.h>
#include "../ogres.h"

inherit STORAGE"3rd.c";

void create(){
   ::create();
   set_exits(([
       "north" : ROOMS"ogremaze36",
       "west" : ROOMS"ogremaze37",
       "south" : ROOMS"ogremaze38",
   ]));

}