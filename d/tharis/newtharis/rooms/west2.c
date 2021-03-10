#include <std.h>
#include "../tharis.h"
inherit STORAGE"rich";

void create(){
   ::create();
   set_long(::query_long()+"%^RESET%^\n");
   set_exits(([
      "east" : ROOMS"west1",
      "west" : ROOMS"west3",
   ]));
}