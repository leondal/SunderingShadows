#include <std.h>
#include "../area_stuff.h"

inherit TOMB;

void create()
{
    ::create();
    set_exits(([
        //"north" : ELROOMST+"1_11",
        "south" : ELROOMST+"1_10"
        //"east" : ELROOMST+"1_3",
        //"west" : ELROOMST+"1_10",
    ]));
}
