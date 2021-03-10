#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"54",
        "east" : ELROOMSD+"40",
        "south" : ELROOMSD+"24",
        "west" : ELROOMSD+"38",
        
    ]));
}
