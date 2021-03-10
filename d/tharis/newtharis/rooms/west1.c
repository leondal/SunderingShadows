#include <std.h>
#include "../tharis.h"
inherit STORAGE"rich";

void create(){
   ::create();
   set_long(::query_long()+" Just east of here lies the city bazaar.%^RESET%^\n");
   set_exits(([
      "south" : ROOMS"jewelry",
      "east" : ROOMS"square3",
      "north" : ROOMS"tharis_healer",
      "west" : ROOMS"west2",
   ]));
}