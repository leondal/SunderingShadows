//forest50.c

#include "../../newbie.h"

inherit FOREST"inherit/forestedge";
//inherit the base room for the edge of the forest

void create(){
    ::create();
    set_exits(([
        "southeast":FOREST"forest58",
        "south":FOREST"forest57",
        "southwest":FOREST"forest56",
        "west":FOREST"forest49",
        "northwest":FOREST"forest42",
    ]));
}
