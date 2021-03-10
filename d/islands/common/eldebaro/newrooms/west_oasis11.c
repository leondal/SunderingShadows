#include <std.h>
#include "../area_stuff.h"

inherit WESTOASIS;

void create()
{
    ::create();
    set_exits(([
        "south" : ELROOMSW+"10",
        "east" : ELROOMSW+"14",
        "north" : ELROOMSW+"12",
        "west" : ELROOMSW+"8",
    ]));
}
