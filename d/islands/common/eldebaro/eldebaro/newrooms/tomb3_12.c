#include <std.h>
#include "../area_stuff.h"

inherit TOMB;

void create()
{
    ::create();
    set_exits(([
        "north" : ELROOMST + "3_14",
        //"northeast" : ELROOMST + "3_11",
        "east" : ELROOMST + "3_13",
        //"southeast" : ELROOMST + "3_9",
        //"south" : ELROOMST+"3_4",  
        //"southwest" : ELROOMST + "3_10",
        "west" : ELROOMST + "3_11",
        //"northwest" : ELROOMST + "3_10",        
    ]));
}
