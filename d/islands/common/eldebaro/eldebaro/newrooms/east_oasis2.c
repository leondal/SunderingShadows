#include <std.h>
#include "../area_stuff.h"

inherit EASTOASIS;

void create()
{
    ::create();
    set_exits(([
        "south" : ELROOMSE+"3",
        "west" : ELROOMSE+"5",
        "north" : ELROOMSE+"1",
    ]));
}
