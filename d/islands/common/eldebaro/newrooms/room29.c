#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        "north" : ELROOMSD+"44",
        "south" : ELROOMSD+"14",
        "west" : ELROOMSD+"28",        
    ]));
}
