
#include <std.h>
#include "../ogres.h"

inherit STORAGE"3rd.c";

void create(){
   ::create();
   set_exits(([
       "west" : ROOMS"ogremaze9",
       "south" : ROOMS"ogremaze8",

   ]));

}