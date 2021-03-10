#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"150",
        "east" : ELROOMSD+"136",
        //"south" : ELROOMSD+"22",
        //"west" : ELROOMSD+"36",
        
    ]));
}
