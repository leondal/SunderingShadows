#include <std.h>
#include "../area_stuff.h"

inherit ASANTRATOMB;

void create()
{
    ::create();
    set_exits(([
        "north" : ELROOMST + "4_19",
        //"northeast" : ELROOMST + "3_1",
        //"east" : ELROOMST + "4_18",
        //"southeast" : ELROOMST + "3_3",
        //"south" : ELROOMST + "4_20",  
        //"southwest" : ELROOMST + "3_2",
        //"west" : ELROOMST + "4_17",
        //"northwest" : ELROOMST + "3_9",        
    ]));
}
