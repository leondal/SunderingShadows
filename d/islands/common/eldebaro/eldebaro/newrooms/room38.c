#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"53",
        "east" : ELROOMSD+"39",
        "south" : ELROOMSD+"23",
        "west" : ELROOMSD+"37",
        
    ]));
}
