#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"40",
        "east" : ELROOMSD+"26",
        "south" : ELROOMSD+"10",
        "west" : ELROOMSD+"24",
        
    ]));
}
