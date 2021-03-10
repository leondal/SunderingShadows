#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"152",
        "east" : ELROOMSD+"138",
        //"south" : ELROOMSD+"22",
        "west" : ELROOMSD+"136",
        
    ]));
}
