#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"35",
        "east" : ELROOMSD+"21",
        "south" : ELROOMSD+"6",
        "west" : ELROOMSD+"19",
        
    ]));
}
