#include <std.h>
#include "../tharis.h"
inherit STORAGE"sewer";

void create(){
   ::create();
   set_long(::query_long()+"%^RESET%^\n");
   set_exits(([
      "east" : SEWERS"sewer3",
      "west" : SEWERS"sewer5",
   ]));
}

void reset(){
  ::reset();
  if(!present("chest")){
    if(random(2)) new("/d/hm_quest/chests/chest6")->move(TO);
    else new("/d/hm_quest/chests/chest21")->move(TO);
  }
}

