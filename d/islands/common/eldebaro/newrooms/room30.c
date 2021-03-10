#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        "south" : ELROOMSD+"15",
        "east" : ELROOMSD+"31",
        "north" : ELROOMSD+"45",
    ]));
}
