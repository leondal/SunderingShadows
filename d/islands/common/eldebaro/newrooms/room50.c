#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        //"north" : ELROOMSD+"62",
        "east" : ELROOMSD+"51",
        "south" : ELROOMSD+"35",
        "west" : ELROOMSD+"49",        
    ]));
}
