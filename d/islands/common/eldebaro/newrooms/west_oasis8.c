#include <std.h>
#include "../area_stuff.h"

inherit WESTOASIS;

void create()
{
    ::create();
    set_exits(([
        "south" : ELROOMSW+"9",
        "east" : ELROOMSW+"11",
        "north" : ELROOMSW+"7",
        "west" : ELROOMSW+"5",
    ]));
}
