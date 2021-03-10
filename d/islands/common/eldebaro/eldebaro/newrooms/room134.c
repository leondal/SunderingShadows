#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        //"north" : ELROOMSD+"147",
        //"east" : ELROOMSD+"135",
        //"south" : ELROOMSD+"114",
        "west" : ELROOMSD+"133",
        
    ]));
}
