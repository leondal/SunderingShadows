
#include <std.h>
#include "../ogres.h"

inherit STORAGE"3rd.c";

void create(){
   ::create();
set_long(::query_long()+"%^RESET%^%^YELLOW%^The cavern branches here, "+
"and you notice that to head further east, you can't get back the "+
"way you came... %^RESET%^\n");
   set_exits(([
       "west" : ROOMS"3_10",
       "northeast" : ROOMS"ogremaze2",
       "east" : ROOMS"ogremaze3",
       "southeast" : ROOMS"ogremaze4",

   ]));

}