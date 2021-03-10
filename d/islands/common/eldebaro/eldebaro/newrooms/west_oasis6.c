#include <std.h>
#include "../area_stuff.h"

inherit WESTOASIS;

void create()
{
    ::create();
    set_exits(([
        "south" : ELROOMSW+"5",
        "east" : ELROOMSW+"7",
        //"north" : ELROOMSW+"6",
        "west" : ELROOMSW+"1",
    ]));
}
