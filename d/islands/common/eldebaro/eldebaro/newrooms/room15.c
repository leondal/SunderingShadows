#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        "south" : ELROOMSD+"1",
        "east" : ELROOMSD+"16",
        "north" : ELROOMSD+"30",
    ]));
}
