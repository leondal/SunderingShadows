#include <std.h>
#include "../area_stuff.h"

inherit WESTOASIS;

void create()
{
    ::create();
    set_exits(([
        "south" : ELROOMSW+"4",
        "east" : ELROOMSW+"8",
        "north" : ELROOMSW+"6",
        "west" : ELROOMSW+"2",
    ]));
}
