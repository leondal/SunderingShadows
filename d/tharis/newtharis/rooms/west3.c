#include <std.h>
#include "../tharis.h"
inherit STORAGE"rich";

void create(){
   ::create();
   set_long(::query_long()+"%^RESET%^\n");
   set_exits(([
      "west" : ROOMS"west4",
      "east" : ROOMS"west2",
   ]));
}
