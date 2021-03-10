#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        "north" : ELROOMSD+"29",
        "south" : ELROOMSE+"1",
        "west" : ELROOMSD+"13",        
    ]));
}
