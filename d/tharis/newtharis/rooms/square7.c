#include <std.h>
#include "../tharis.h"
inherit STORAGE"bazaar.c";

void create(){
   ::create();
   set_long(::query_long()+" East of here, the road narrows as it meanders into the slums.%^RESET%^\n");
   set_exits(([
      "south" : ROOMS"square6",
      "east" : ROOMS"east1",
      "north" : ROOMS"square8",
      "west" : ROOMS"fountain",
      "northwest" : ROOMS"square1",
      "southwest" : ROOMS"square5",
   ]));
}