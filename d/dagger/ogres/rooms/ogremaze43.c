
#include <std.h>
#include "../ogres.h"

inherit STORAGE"3rd.c";

void create(){
   ::create();
   set_exits(([
       "west" : ROOMS"ogremaze42",
       "south" : ROOMS"ogremaze44",
   ]));

}