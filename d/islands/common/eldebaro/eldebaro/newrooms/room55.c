#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        //"north" : ELROOMSD+"62",
        "east" : ELROOMSD+"56",
        "south" : ELROOMSD+"40",
        "west" : ELROOMSD+"54",        
    ]));
}
