#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"32",
        "east" : ELROOMSD+"18",
        "south" : ELROOMSD+"3",
        "west" : ELROOMSD+"16",
        
    ]));
}
