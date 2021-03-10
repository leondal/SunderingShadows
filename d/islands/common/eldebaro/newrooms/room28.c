#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"43",
        "east" : ELROOMSD+"29",
        "south" : ELROOMSD+"13",
        "west" : ELROOMSD+"27",
        
    ]));
}
