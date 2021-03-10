#include <std.h>
#include "../tharis.h"
inherit STORAGE"bazaar.c";

void create(){
   ::create();
   set_long(::query_long()+" North of here lies the city trade district.%^RESET%^\n");
   set_exits(([
      "west" : ROOMS"square2",
      "east" : ROOMS"square8",
      "south" : ROOMS"fountain",
      "southwest" : ROOMS"square3",
      "southeast" : ROOMS"square7",
      "north" : ROOMS"north4",
   ]));
}

void reset(){
    ::reset();
    if(!present("vendor")) new(MOBS"f_vendor.c")->move(TO);
}