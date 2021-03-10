#include <std.h>
#include "../area_stuff.h"

inherit TOMB;

void create()
{
    ::create();
    set_exits(([
        "north" : ELROOMST+"1_10",
        //"south" : ELROOMST+"1_5"
        //"east" : ELROOMST+"1_3",
        //"west" : ELROOMST+"1_10",
    ]));
}
