#include <std.h>
#include "../area_stuff.h"

inherit TOMB;

void create()
{
    ::create();
    set_exits(([
        //"north" : ELROOMST + "2_5",
        //"east" : ELROOMST + "2_7",
        //"south" : ELROOMST + "2_6", 
        "west" : ELROOMST + "2_6",        
    ]));
}
