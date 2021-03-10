#include <std.h>
#include "../area_stuff.h"

inherit TOMBHALL;

void create()
{
    ::create();
    set_exits(([
        "north" : ELROOMST+"1_11",
        "south" : ELROOMST+"1_9",
        "east" : ELROOMST+"1_8",
        //"west" : ELROOMST+"1_10",
    ]));
}
