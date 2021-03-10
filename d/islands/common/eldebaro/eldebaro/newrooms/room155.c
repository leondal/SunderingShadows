#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        //"north" : ELROOMSD+"150",
        "east" : ELROOMSD+"156",
        "south" : ELROOMSD+"140",
        "west" : ELROOMSD+"154",
        
    ]));
}
