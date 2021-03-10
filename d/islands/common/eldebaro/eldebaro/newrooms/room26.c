#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"41",
        "east" : ELROOMSD+"27",
        "south" : ELROOMSD+"11",
        "west" : ELROOMSD+"25",
        
    ]));
}
