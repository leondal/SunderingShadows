#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        "east" : ELROOMSD+"47",
        "south" : ELROOMSD+"31",
        "west" : ELROOMSD+"45",        
    ]));
}
