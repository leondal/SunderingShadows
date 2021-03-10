#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"47",
        "east" : ELROOMSD+"33",
        "south" : ELROOMSD+"17",
        "west" : ELROOMSD+"31",
        
    ]));
}
