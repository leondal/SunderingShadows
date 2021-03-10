#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        "west" : ELROOMSD+"1",
        "east" : ELROOMSD+"3",
        "north" : ELROOMSD+"16",
    ]));
}
