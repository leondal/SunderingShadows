#include <std.h>
#include "../tharis.h"
inherit STORAGE"bazaar.c";

void create(){
   ::create();
   set_long(::query_long()+"%^RESET%^\n");
   set_exits(([
      "east" : ROOMS"square5",
      "northeast" : ROOMS"fountain",
      "north" : ROOMS"square3",
   ]));
}