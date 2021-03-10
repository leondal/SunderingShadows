//forest58.c

#include "../../newbie.h"

inherit FOREST"inherit/forestedge";
//inherit the base room for the edge of the forest

void create(){
    ::create();
    set_exits(([
        "southwest":FOREST"forest66",
        "west":FOREST"forest57",
        "northwest":FOREST"forest50",
    ]));
}
