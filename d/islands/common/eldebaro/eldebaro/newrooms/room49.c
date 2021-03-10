#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        //"north" : ELROOMSD+"62",
        "east" : ELROOMSD+"50",
        "south" : ELROOMSD+"34",
        "west" : ELROOMSD+"48",        
    ]));
}
