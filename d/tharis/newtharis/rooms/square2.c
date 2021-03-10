#include <std.h>
#include "../tharis.h"
inherit STORAGE"bazaar.c";

void create(){
   ::create();
   set_long(::query_long()+"%^RESET%^\n");
   set_exits(([
      "east" : ROOMS"square1",
      "south" : ROOMS"square3",
      "southeast" : ROOMS"fountain",
   ]));
}

void reset(){
    ::reset();
    if(!present("vendor")) new(MOBS"met_vendor.c")->move(TO);
}

