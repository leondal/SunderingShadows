#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        //"north" : ELROOMSD+"150",
        "east" : ELROOMSD+"155",
        "south" : ELROOMSD+"139",
        "west" : ELROOMSD+"153",
        
    ]));
}
