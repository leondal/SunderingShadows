#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        "north" : ELROOMSD+"27",
        "east" : ELROOMSD+"13",
        "west" : ELROOMSD+"11",        
    ]));
}
