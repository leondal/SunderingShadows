//forest71.c

#include "../../newbie.h"

inherit FOREST"inherit/forestridge";
//inherit the base room for the ridge area

void create(){
    ::create();
    set_exits(([
        "north":FOREST"forest64",
        "northeast":FOREST"forest65",
        "southwest":FOREST"forest73",
        "west":FOREST"forest70",
        "northwest":FOREST"forest63",
    ]));
}
