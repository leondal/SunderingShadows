#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        "north" : ELROOMSD+"62",
        "east" : ELROOMSD+"48",
        "south" : ELROOMSD+"32",
        "west" : ELROOMSD+"46",        
    ]));
}
