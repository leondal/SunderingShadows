#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"33",
        "east" : ELROOMSD+"19",
        "south" : ELROOMSD+"4",
        "west" : ELROOMSD+"17",
        
    ]));
}
