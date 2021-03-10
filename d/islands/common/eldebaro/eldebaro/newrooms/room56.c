#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        //"north" : ELROOMSD+"62",
        "east" : ELROOMSD+"57",
        "south" : ELROOMSD+"41",
        "west" : ELROOMSD+"55",        
    ]));
}
