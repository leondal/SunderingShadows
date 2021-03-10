#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        "north" : ELROOMSD+"24",
        "east" : ELROOMSD+"10",
        "west" : ELROOMSD+"8",        
    ]));
}
