#include <std.h>
#include "../area_stuff.h"

inherit EASTOASIS;

void create()
{
    ::create();
    set_exits(([
        "south" : ELROOMSE+"2",
        "west" : ELROOMSE+"6",
        "north" : ELROOMSD+"14",
    ]));
}
