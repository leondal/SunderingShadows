#include <std.h>
#include "../area_stuff.h"

inherit TOMB;

void create()
{
    ::create();
    set_exits(([
        "north" : ELROOMST + "2_10",
        "east" : ELROOMST + "2_8",
        //"south" : ELROOMST + "2_6", 
        //"west" : ELROOMST + "2_9",        
    ]));
}
