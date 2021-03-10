//forest72.c

#include "../../newbie.h"

inherit FOREST"inherit/forestridge";
//inherit the base room for the ridge area

void create(){
    ::create();
    set_exits(([
        "north":FOREST"forest69",
        "northeast":FOREST"forest70",
        "east":FOREST"forest73",
        "south":ROAD"sfroad2",
        "northwest":FOREST"forest68",
        "southwest":FOREST"forest72a",
    ]));
}
