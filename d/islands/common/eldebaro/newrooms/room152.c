#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"167",
        "east" : ELROOMSD+"153",
        "south" : ELROOMSD+"137",
        "west" : ELROOMSD+"151",
        
    ]));
}
