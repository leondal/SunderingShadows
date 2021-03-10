//cave39.c
#include <std.h>
#include "echoes.h"

inherit OGRES;

void create(){
    ::create();
    set_long(
      ""+TO->query_long()+"The cavern is very dark here, and an ominous "+
      "dread hangs near the end of the cavern to the east."
      "\n"
    );
    set_exits(([
        "west" : ROOMS"cave38",
        "east" : ROOMS"cave40"
   	]));
}

void reset() {
   ::reset();
   if(!present("koboldf") && !random(3)) {
     find_object_or_load(MOBS"koboldf")->move(TO);
   }
}