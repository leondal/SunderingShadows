#include <std.h>
#include "../ogres.h"

inherit STORAGE"2nd.c";

void create(){
   ::create();
    set_long(::query_long()+"%^BLACK%^%^BOLD%^There is a hole here...%^RESET%^.\n");
   set_exits(([
      "northeast" : ROOMS"2_38",
      "hole" : ROOMS"3_10",
   ]));

}
