
#include <std.h>
#include "../ogres.h"

inherit STORAGE"3rd.c";

void create(){
   ::create();
   set_exits(([
       "southwest" : ROOMS"ogremaze46",
       "east" : ROOMS"ogremaze44",
   ]));

}