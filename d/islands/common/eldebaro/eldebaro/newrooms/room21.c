#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"36",
        "east" : ELROOMSD+"22",
        "south" : ELROOMSD+"7",
        "west" : ELROOMSD+"20",
        
    ]));
}
