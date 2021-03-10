#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        "east" : ELROOMSD+"46",
        "south" : ELROOMSD+"30",
        //"west" : ELROOMSD+"58",        
    ]));
}
