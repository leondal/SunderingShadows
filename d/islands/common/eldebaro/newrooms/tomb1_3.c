#include <std.h>
#include "../area_stuff.h"

inherit TOMB;

void create()
{
    ::create();
    set_exits(([
        "north" : ELROOMST+"1_2",
        //"south" : ELROOMST+"1_3"
        "east" : ELROOMST+"1_4",
        "west" : ELROOMST+"1_8",
    ]));
}
