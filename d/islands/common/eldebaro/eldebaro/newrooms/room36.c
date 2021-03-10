#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"51",
        "east" : ELROOMSD+"37",
        "south" : ELROOMSD+"21",
        "west" : ELROOMSD+"35",
        
    ]));
}
