#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"31",
        "east" : ELROOMSD+"17",
        "south" : ELROOMSD+"2",
        "west" : ELROOMSD+"15",
        
    ]));
}
