#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([        
        "north" : ELROOMSD+"37",
        "east" : ELROOMSD+"23",
        "south" : DOCKROOM,
        "west" : ELROOMSD+"21",        
    ]));
}
