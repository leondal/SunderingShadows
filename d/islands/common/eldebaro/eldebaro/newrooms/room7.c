#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        "north" : ELROOMSD+"21",
        "east" : DOCKROOM,
        "west" : ELROOMSD+"6",        
    ]));
}
