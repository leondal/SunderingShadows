#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        //"north" : ELROOMSD+"150",
        "east" : ELROOMSD+"154",
        "south" : ELROOMSD+"138",
        "west" : ELROOMSD+"152",
        
    ]));
}
