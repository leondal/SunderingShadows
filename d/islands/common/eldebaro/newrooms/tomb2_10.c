#include <std.h>
#include "../area_stuff.h"

inherit TOMBHALL;

void create()
{
    ::create();
    set_exits(([
        "north" : ELROOMST + "2_11",
        //"east" : ELROOMST + "2_8",
        "south" : ELROOMST + "2_9", 
        //"west" : ELROOMST + "2_9",        
    ]));
}
