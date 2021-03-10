#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        "north" : ELROOMSD+"19",
        "east" : ELROOMSD+"6",
        "west" : ELROOMSD+"4",        
    ]));
}
