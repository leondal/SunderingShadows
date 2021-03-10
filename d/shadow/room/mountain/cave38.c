//cave38.c
#include <std.h>
#include "echoes.h"

inherit OGRES;

void create(){
    ::create();
    set_long(
       ""+TO->query_long()+"The cavern seems to darken further east, "+
       "and an ominous feeling emerges from the end of the cavern there."
      "\n"
    );

    set_exits(([
        "west" : ROOMS"cave37",
        "east" : ROOMS"cave39"
   	]));
}
