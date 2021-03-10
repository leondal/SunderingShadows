//forest65.c

#include "../../newbie.h"

inherit FOREST"inherit/forestridge";
//inherit the base room for the ridge area

void create(){
    ::create();
    set_exits(([
        "north":FOREST"forest56",
        "northeast":FOREST"forest57",
        "east":FOREST"forest66",
        "southwest":FOREST"forest71",
        "west":FOREST"forest64",
        "northwest":FOREST"forest55",
    ]));
}
