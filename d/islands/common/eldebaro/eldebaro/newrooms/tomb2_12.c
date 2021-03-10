#include <std.h>
#include "../area_stuff.h"

inherit TOMB;

void create()
{
    ::create();
    set_exits(([
        //"north" : ELROOMST + "2_11",
        "east" : ELROOMST + "2_11",
        //"south" : ELROOMST + "2_10", 
        //"west" : ELROOMST + "2_12",        
    ]));
}
