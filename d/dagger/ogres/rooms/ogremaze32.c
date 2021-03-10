
#include <std.h>
#include "../ogres.h"

inherit STORAGE"3rd.c";

void create(){
   ::create();
   set_exits(([
       "east" : ROOMS"ogremaze41",
       "north" : ROOMS"ogremaze4",
       "southwest" : ROOMS"ogremaze33",
   ]));

}