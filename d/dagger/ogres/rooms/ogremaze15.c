
#include <std.h>
#include "../ogres.h"

inherit STORAGE"3rd.c";

void create(){
   ::create();
   set_exits(([
       "east" : ROOMS"ogremaze16",
       "north" : ROOMS"ogremaze14",
       "west" : ROOMS"ogremaze6",

   ]));

}