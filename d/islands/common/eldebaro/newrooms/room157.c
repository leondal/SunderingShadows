#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        //"north" : ELROOMSD+"150",
        "east" : ELROOMSD+"158",
        "south" : ELROOMSD+"142",
        "west" : ELROOMSD+"156",
        
    ]));
}
