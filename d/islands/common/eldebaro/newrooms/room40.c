#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"55",
        "east" : ELROOMSD+"41",
        "south" : ELROOMSD+"25",
        "west" : ELROOMSD+"39",
        
    ]));
}
