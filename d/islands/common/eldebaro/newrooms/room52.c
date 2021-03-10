#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        //"north" : ELROOMSD+"62",
        "east" : ELROOMSD+"53",
        "south" : ELROOMSD+"37",
        "west" : ELROOMSD+"51",        
    ]));
}
