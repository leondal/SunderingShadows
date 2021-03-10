#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        //"north" : ELROOMSD+"52",
        "east" : ELROOMSD+"63",
        "south" : ELROOMSD+"47",
        "west" : ELROOMSD+"61",
        
    ]));
}
