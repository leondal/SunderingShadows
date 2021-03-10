#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        //"north" : ELROOMSD+"121",
        "east" : ELROOMSD+"110",
        "south" : ELROOMSD+"94",
        "west" : ELROOMSD+"108",
        
    ]));
}
