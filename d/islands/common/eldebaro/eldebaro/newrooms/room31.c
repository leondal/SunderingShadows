#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"46",
        "east" : ELROOMSD+"32",
        "south" : ELROOMSD+"16",
        "west" : ELROOMSD+"30",
        
    ]));
}
