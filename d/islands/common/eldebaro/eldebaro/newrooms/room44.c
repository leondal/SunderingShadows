#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        "north" : ELROOMSD+"59",
        "south" : ELROOMSD+"29",
        "west" : ELROOMSD+"43",        
    ]));
}
