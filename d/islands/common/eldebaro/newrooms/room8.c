#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        "north" : ELROOMSD+"23",
        "east" : ELROOMSD+"9",
        "west" : DOCKROOM,        
    ]));
}
