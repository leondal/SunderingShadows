#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        //"north" : ELROOMSD+"150",
        "east" : ELROOMSD+"157",
        "south" : ELROOMSD+"141",
        "west" : ELROOMSD+"155",
        
    ]));
}
