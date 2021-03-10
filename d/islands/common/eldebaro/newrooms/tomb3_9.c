#include <std.h>
#include "../area_stuff.h"

inherit TOMBHALL;

void create()
{
    ::create();
    set_exits(([
        //"north" : ELROOMST + "3_3",
        //"northeast" : ELROOMST + "3_1",
        //"east" : ELROOMST + "3_7",
          "southeast" : ELROOMST + "3_1",
        //"south" : ELROOMST+"3_4",  
        //"southwest" : ELROOMST + "3_2",
        //"west" : ELROOMST + "3_8",
        "northwest" : ELROOMST + "3_10",        
    ]));
}
