#include <std.h>
#include "../area_stuff.h"

inherit WESTOASIS;

void create()
{
    ::create();
    set_exits(([
        //"south" : ELROOMSW+"3",
        "east" : ELROOMSW+"9",
        "north" : ELROOMSW+"5",
        "west" : ELROOMSW+"3",
    ]));
}
