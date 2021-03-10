#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"58",
        "east" : ELROOMSD+"44",
        "south" : ELROOMSD+"28",
        "west" : ELROOMSD+"42",
        
    ]));
}
