#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        "south" : ELROOMSW+"1",
        "east" : ELROOMSD+"2",
        "north" : ELROOMSD+"15",
    ]));
}
