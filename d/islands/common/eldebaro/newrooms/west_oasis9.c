#include <std.h>
#include "../area_stuff.h"

inherit WESTOASIS;

void create()
{
    ::create();
    set_exits(([
        //"south" : ELROOMSW+"9",
        "east" : ELROOMSW+"10",
        "north" : ELROOMSW+"8",
        "west" : ELROOMSW+"4",
    ]));
}
