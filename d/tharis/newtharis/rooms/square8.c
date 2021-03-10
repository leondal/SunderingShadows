#include <std.h>
#include "../tharis.h"
inherit STORAGE"bazaar.c";

void create(){
   ::create();
   set_long(::query_long()+"%^RESET%^\n");
   set_exits(([
      "south" : ROOMS"square7",
      "west" : ROOMS"square1",
      "southwest" : ROOMS"fountain",
   ]));
}

void reset(){
    ::reset();
    if(!present("vendor")) new(MOBS"cloth_vendor.c")->move(TO);
}

