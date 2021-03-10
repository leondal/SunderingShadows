#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        "north" : ELROOMSD+"26",
        "east" : ELROOMSD+"12",
        "west" : ELROOMSD+"10",        
    ]));
}
