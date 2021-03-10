#include <std.h>
#include "../tharis.h"
inherit STORAGE"bazaar.c";

void create(){
   ::create();
   set_long(::query_long()+" West of here lies the upper-class district of the city.%^RESET%^\n");
   set_exits(([
      "east" : ROOMS"fountain",
      "northeast" : ROOMS"square1",
      "west" : ROOMS"west1",
      "south" : ROOMS"square4",
      "north" : ROOMS"square2",
      "southeast" : ROOMS"square5",
   ]));
}

void reset(){
    ::reset();
    if(!present("vendor")) new(MOBS"tb_vendor.c")->move(TO);
}