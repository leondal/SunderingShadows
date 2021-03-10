//forest73.c

#include "../../newbie.h"

inherit FOREST"inherit/forestridge";
//inherit the base room for the ridge area

void create(){
    ::create();
    set_exits(([
        "north":FOREST"forest70",
        "northeast":FOREST"forest71",
        "southwest":ROAD"sfroad2",
        "west":FOREST"forest72",
        "northwest":FOREST"forest69",
    ]));
}
