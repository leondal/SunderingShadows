//forest70.c

#include "../../newbie.h"

inherit FOREST"inherit/forestridge";
//inherit the base room for the ridge area

void create(){
    ::create();
    set_exits(([
        "north":FOREST"forest63",
        "northeast":FOREST"forest64",
        "east":FOREST"forest71",
        "south":FOREST"forest73",
        "southwest":FOREST"forest72",
        "west":FOREST"forest69",
        "northwest":FOREST"forest62",
    ]));
}
