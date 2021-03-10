#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"42",
        "east" : ELROOMSD+"28",
        "south" : ELROOMSD+"12",
        "west" : ELROOMSD+"26",
        
    ]));
}
