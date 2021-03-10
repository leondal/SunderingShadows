#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"156",
        "east" : ELROOMSD+"142",
        "south" : ELROOMSD+"126",
        "west" : ELROOMSD+"140",
        
    ]));
}
