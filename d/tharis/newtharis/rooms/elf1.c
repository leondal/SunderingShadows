#include <std.h>
#include "../tharis.h"
inherit STORAGE"elf";

void create(){
   ::create();
   set_long(::query_long()+" A small, abandoned office lies to the south. Further west, the road meanders into the city slums.%^RESET%^\n");
   set_exits(([
      "east" : ROOMS"elf2",
      "west" : ROOMS"east3",
      "south" : ROOMS"office",
   ]));
}