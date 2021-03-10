#include <std.h>
#include "../area_stuff.h"

inherit WESTOASIS;

void create()
{
    ::create();
    set_exits(([
        //"south" : ELROOMSW+"9",
        "east" : ELROOMSW+"15",
        "north" : ELROOMSW+"11",
        "west" : ELROOMSW+"9",
    ]));
}
