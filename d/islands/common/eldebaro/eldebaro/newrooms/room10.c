#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        "north" : ELROOMSD+"25",
        "east" : ELROOMSD+"11",
        "west" : ELROOMSD+"9",        
    ]));
}
