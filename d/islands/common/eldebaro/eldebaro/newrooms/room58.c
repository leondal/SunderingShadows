#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        //"north" : ELROOMSD+"62",
        "east" : ELROOMSD+"59",
        "south" : ELROOMSD+"43",
        "west" : ELROOMSD+"57",        
    ]));
}
