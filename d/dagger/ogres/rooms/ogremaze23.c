
#include <std.h>
#include "../ogres.h"

inherit STORAGE"3rd.c";

void create(){
   ::create();
   set_exits(([
       "northwest" : ROOMS"ogremaze17",
       "southwest" : ROOMS"ogremaze18",

   ]));

}