#include <std.h>
#include "../area_stuff.h"

inherit TOMBHALL;

void create()
{
    ::create();
    set_exits(([
        //"north" : ELROOMST+"1_1",
        //"south" : ELROOMST+"1_3"
        "east" : ELROOMST+"1_5",
        "west" : ELROOMST+"1_3",
    ]));
}
