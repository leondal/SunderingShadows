#include <std.h>
#include "../area_stuff.h"

inherit TOMBHALL;

void create()
{
    ::create();
    set_exits(([
        "north" : ELROOMST + "4_6",
        //"northeast" : ELROOMST + "3_1",
        //"east" : ELROOMST + "4_4",
        //"southeast" : ELROOMST + "3_3",
        "south" : ELROOMST + "4_4",  
        //"southwest" : ELROOMST + "3_2",
        //west" : ELROOMST + "4_3",
        //"northwest" : ELROOMST + "3_9",        
    ]));
}
