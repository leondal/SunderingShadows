
#include <std.h>
#include "../ogres.h"

inherit STORAGE"3rd.c";

void create(){
   ::create();
   set_exits(([
       "west" : ROOMS"ogremaze32",
       "northeast" : ROOMS"ogremaze42",
   ]));

}