//forest35.c

#include "../../newbie.h"

inherit FOREST"inherit/forestlake";
//inherit the base room with fishing for near the lake

void create(){
    ::create();
    set_exits(([
        "northeast":FOREST"forest26",
        "east":FOREST"forest36",
        "southeast":FOREST"forest43",
        "southwest":ROAD"wfroad7",
    ]));
}
