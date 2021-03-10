#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"155",
        "east" : ELROOMSD+"141",
        //"south" : ELROOMSD+"22",
        "west" : ELROOMSD+"139",
        
    ]));
}
