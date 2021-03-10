//cave15.c
#include <std.h>
#include "echoes.h"

inherit ECHOES;

void create(){
    ::create();
    set_long(
      ""+TO->query_long()+"Here, another tunnel braches off the main "+
         "one, leading east.\n"
    );
    set_exits(([
        "north" : ROOMS"cave16",
        "east" : ROOMS"cave20",
        "south" : ROOMS"cave14"
   	]));
}
/*
void reset() {
  ::reset();
  if(!present("mountain dwarf")) {
   if(sizeof(children(MOBS"dwarf")) < 10) 
    new(MOBS"dwarf")->move(TO);
  }
}
*/