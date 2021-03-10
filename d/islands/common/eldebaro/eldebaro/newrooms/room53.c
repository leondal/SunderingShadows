#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        //"north" : ELROOMSD+"62",
        "east" : ELROOMSD+"54",
        "south" : ELROOMSD+"38",
        "west" : ELROOMSD+"52",        
    ]));
}
