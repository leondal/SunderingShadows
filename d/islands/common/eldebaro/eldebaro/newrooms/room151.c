#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        //"north" : ELROOMSD+"150",
        "east" : ELROOMSD+"152",
        "south" : ELROOMSD+"136",
        "west" : ELROOMSD+"150",
        
    ]));
}
