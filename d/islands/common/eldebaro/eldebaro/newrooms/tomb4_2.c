#include <std.h>
#include "../area_stuff.h"

inherit TOMBHALL;

void create()
{
    ::create();
    set_exits(([
        //"north" : ELROOMST + "2_2",
        //"northeast" : ELROOMST + "3_1",
        "east" : ELROOMST + "4_3",
        //"southeast" : ELROOMST + "3_3",
        //"south" : ELROOMST+"1_2",  
        //"southwest" : ELROOMST + "3_2",
        "west" : ELROOMST + "4_1",
        //"northwest" : ELROOMST + "3_9",        
    ]));
}
