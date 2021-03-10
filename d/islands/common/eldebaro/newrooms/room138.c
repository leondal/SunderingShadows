#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"153",
        "east" : ELROOMSD+"139",
        //"south" : ELROOMSD+"22",
        "west" : ELROOMSD+"137",
        
    ]));
}
