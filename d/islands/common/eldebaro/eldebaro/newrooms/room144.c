#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"159",
        "east" : ELROOMSD+"145",
        //"south" : ELROOMSD+"126",
        //"west" : ELROOMSD+"142",
        
    ]));
}
