#include <std.h>
#include "../tharis.h"
inherit STORAGE"bazaar.c";

void create(){
   ::create();
   set_long(::query_long()+" South from here leads a broad roadway, headed towards the mountainside.%^RESET%^\n");
   set_exits(([
      "west" : ROOMS"square4",
      "south" : ROOMS"north5",
      "northeast" : ROOMS"square7",
      "northwest" : ROOMS"square3",
      "north" : ROOMS"fountain",
      "east" : ROOMS"square6",
   ]));
}