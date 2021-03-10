#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        //"north" : ELROOMSD+"121",
        //"east" : ELROOMSD+"114",
        //"south" : ELROOMSD+"22",
        "west" : ELROOMSD+"112",
    ]));
}
