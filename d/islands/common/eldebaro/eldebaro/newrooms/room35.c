#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"50",
        "east" : ELROOMSD+"36",
        "south" : ELROOMSD+"20",
        "west" : ELROOMSD+"34",
        
    ]));
}
