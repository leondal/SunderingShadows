#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        "north" : ELROOMSD+"20",
        "east" : ELROOMSD+"7",
        "west" : ELROOMSD+"5",        
    ]));
}
