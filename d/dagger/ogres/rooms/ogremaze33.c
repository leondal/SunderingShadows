
#include <std.h>
#include "../ogres.h"

inherit STORAGE"3rd.c";

void create(){
   ::create();
   set_exits(([
       "northeast" : ROOMS"ogremaze32",
       "southwest" : ROOMS"ogremaze34",
   ]));

}