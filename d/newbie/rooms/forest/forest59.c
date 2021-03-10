//forest59

#include "../../newbie.h"

inherit FOREST"inherit/forestedge";
//inherit the base room for the edge of the forest

void create(){
    ::create();
    set_exits(([
        "northeast":FOREST"forest51",
        "east":FOREST"forest60",
        "southeast":FOREST"forest67",
    ]));
}
