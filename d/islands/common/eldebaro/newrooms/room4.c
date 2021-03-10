#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        "north" : ELROOMSD+"18",
        "east" : ELROOMSD+"5",
        "west" : ELROOMSD+"3",        
    ]));
}
