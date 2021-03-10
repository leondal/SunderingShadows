#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"34",
        "east" : ELROOMSD+"20",
        "south" : ELROOMSD+"5",
        "west" : ELROOMSD+"18",
        
    ]));
}
