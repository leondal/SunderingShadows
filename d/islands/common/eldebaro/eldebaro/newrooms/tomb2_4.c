#include <std.h>
#include "../area_stuff.h"

inherit TOMB;

void create()
{
    ::create();
    set_exits(([
        //"north" : ELROOMST + "2_2",
        //"east" : ELROOMST + "2_4",
        "south" : ELROOMST + "2_5", 
        "west" : ELROOMST + "2_3",        
    ]));
}
