//forest68.c

#include "../../newbie.h"

inherit FOREST"inherit/forestridge";
//inherit the base room for the ridge area

void create(){
    ::create();
    set_exits(([
        "north":FOREST"forest61",
        "northeast":FOREST"forest62",
        "east":FOREST"forest69",
        "southeast":FOREST"forest72",
        "west":FOREST"forest67",
        "northwest":FOREST"forest60",
    ]));
}
