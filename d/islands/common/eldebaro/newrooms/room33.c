#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"48",
        "east" : ELROOMSD+"34",
        "south" : ELROOMSD+"18",
        "west" : ELROOMSD+"32",
        
    ]));
}
