#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        "south" : ELROOMSD+"44",
        "west" : ELROOMSD+"58",        
    ]));
}
