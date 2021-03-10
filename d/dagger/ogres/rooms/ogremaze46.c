
#include <std.h>
#include "../ogres.h"

inherit STORAGE"3rd.c";

void create(){
   ::create();
   set_exits(([
       "northeast" : ROOMS"ogremaze45",
       "west" : ROOMS"ogremaze40",
       "south" : ROOMS"ogremaze47",
   ]));

}