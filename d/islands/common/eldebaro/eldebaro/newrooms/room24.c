#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"39",
        "east" : ELROOMSD+"25",
        "south" : ELROOMSD+"9",
        "west" : ELROOMSD+"23",
        
    ]));
}
