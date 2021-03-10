#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        //"north" : ELROOMSD+"116",
        "east" : ELROOMSD+"104",
        "south" : ELROOMSD+"88",
        "west" : ELROOMSD+"102",
        
    ]));
}
