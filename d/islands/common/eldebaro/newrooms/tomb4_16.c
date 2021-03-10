#include <std.h>
#include "../area_stuff.h"

inherit TOMBHALL;

void create()
{
    ::create();
    set_exits(([
        "north" : ELROOMST + "4_14",
        //"northeast" : ELROOMST + "3_1",
        //"east" : ELROOMST + "4_14",
        //"southeast" : ELROOMST + "3_3",
        "south" : ELROOMST + "4_17",  
        //"southwest" : ELROOMST + "3_2",
        //"west" : ELROOMST + "4_15",
        //"northwest" : ELROOMST + "3_9",        
    ]));
}
