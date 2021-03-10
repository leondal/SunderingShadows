#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"38",
        "east" : ELROOMSD+"24",
        "south" : ELROOMSD+"8",
        "west" : ELROOMSD+"22",
        
    ]));
}
