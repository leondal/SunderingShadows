#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        //"north" : ELROOMSD+"62",
        "east" : ELROOMSD+"58",
        "south" : ELROOMSD+"42",
        "west" : ELROOMSD+"56",        
    ]));
}
