#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        //"north" : ELROOMSD+"159",
        //"east" : ELROOMSD+"149",
        //"south" : ELROOMSD+"132",
        "west" : ELROOMSD+"148",
        
    ]));
}
