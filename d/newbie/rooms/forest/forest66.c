//forest43.c

#include "../../newbie.h"

inherit FOREST"inherit/forestedge";
//inherit the base room for the edge of the forest

void create(){
    ::create();
    set_exits(([
        "north":FOREST"forest57",
        "northeast":FOREST"forest58",
        "west":FOREST"forest65",
        "northwest":FOREST"forest56",
    ]));
}
