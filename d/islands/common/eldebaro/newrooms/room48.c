#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        //"north" : ELROOMSD+"62",
        "east" : ELROOMSD+"49",
        "south" : ELROOMSD+"33",
        "west" : ELROOMSD+"47",        
    ]));
}
