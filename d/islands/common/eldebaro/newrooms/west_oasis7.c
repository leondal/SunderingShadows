#include <std.h>
#include "../area_stuff.h"

inherit WESTOASIS;

void create()
{
    ::create();
    set_exits(([
        "south" : ELROOMSW+"8",
        "east" : ELROOMSW+"12",
        //"north" : ELROOMSW+"6",
        "west" : ELROOMSW+"6",
    ]));
}
