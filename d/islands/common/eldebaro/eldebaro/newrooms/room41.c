#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"56",
        "east" : ELROOMSD+"42",
        "south" : ELROOMSD+"26",
        "west" : ELROOMSD+"40",
        
    ]));
}
