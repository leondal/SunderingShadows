//cave36.c
#include <std.h>
#include "echoes.h"

inherit OGRES;

void create(){
    ::create();
    set_exits(([
        "south" : ROOMS"cave35",
        "east" : ROOMS"cave37"
   	]));
}

void reset() {
   ::reset();
   if(!present("koboldf") && !random(3)) {
     find_object_or_load(MOBS"koboldf")->move(TO);
   }
}