#include <std.h>
#include "../tharis.h"
inherit STORAGE"slum";

void create(){
   ::create();
   set_long(::query_long()+" Just west of here lies the city bazaar.\n");
   set_exits(([
      "east" : ROOMS"east2",
      "west" : ROOMS"square7",
   ]));
}