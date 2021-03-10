#include <std.h>
#include "../area_stuff.h"

inherit WESTOASIS;

void create()
{
    ::create();
    set_exits(([
        "south" : ELROOMSW+"2",
        "east" : ELROOMSW+"6",
        "north" : ELROOMSD+"1",
    ]));
}
