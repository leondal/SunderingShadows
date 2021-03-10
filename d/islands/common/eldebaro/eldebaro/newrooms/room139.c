#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"154",
        "east" : ELROOMSD+"140",
        //"south" : ELROOMSD+"22",
        "west" : ELROOMSD+"138",
        
    ]));
}
