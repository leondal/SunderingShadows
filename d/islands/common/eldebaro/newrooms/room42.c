#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"57",
        "east" : ELROOMSD+"43",
        "south" : ELROOMSD+"27",
        "west" : ELROOMSD+"41",
        
    ]));
}
