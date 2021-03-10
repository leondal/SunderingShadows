#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"49",
        "east" : ELROOMSD+"35",
        "south" : ELROOMSD+"19",
        "west" : ELROOMSD+"33",
        
    ]));
}
