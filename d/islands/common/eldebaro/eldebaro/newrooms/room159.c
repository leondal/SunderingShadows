#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        //"north" : ELROOMSD+"150",
        "east" : ELROOMSD+"160",
        "south" : ELROOMSD+"144",
        //"west" : ELROOMSD+"157",
        
    ]));
}
