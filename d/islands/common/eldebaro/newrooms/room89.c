#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        //"north" : ELROOMSD+"103",
        //"east" : ELROOMSD+"89",
        //"south" : ELROOMSD+"64",
        "west" : ELROOMSD+"88",
        
    ]));
}
