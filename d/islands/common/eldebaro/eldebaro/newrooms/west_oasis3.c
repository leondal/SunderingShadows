#include <std.h>
#include "../area_stuff.h"

inherit WESTOASIS;

void create()
{
    ::create();
    set_exits(([
        //"south" : ELROOMSW+"3",
        "east" : ELROOMSW+"4",
        "north" : ELROOMSW+"2",
    ]));
}
