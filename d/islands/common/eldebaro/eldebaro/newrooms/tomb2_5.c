#include <std.h>
#include "../area_stuff.h"

inherit TOMBHALL;

void create()
{
    ::create();
    set_exits(([
        "north" : ELROOMST + "2_4",
        //"east" : ELROOMST + "2_4",
        "south" : ELROOMST + "2_6", 
        //"west" : ELROOMST + "2_3",        
    ]));
}
