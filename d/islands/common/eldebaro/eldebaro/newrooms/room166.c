#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        //"north" : ELROOMSD+"150",
        "east" : ELROOMSD+"167",
        //"south" : ELROOMSD+"135",
        "west" : ELROOMSD+"165",
        
    ]));
}
