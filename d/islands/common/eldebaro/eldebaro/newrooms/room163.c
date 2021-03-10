#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        //"north" : ELROOMSD+"177",
        "east" : ELROOMSD+"164",
        //"south" : ELROOMSD+"144",
        "west" : ELROOMSD+"162",
        
    ]));
}
