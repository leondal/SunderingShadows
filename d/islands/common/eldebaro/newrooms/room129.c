#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        //"north" : ELROOMSD+"141",
        "east" : ELROOMSD+"130",
        "south" : ELROOMSD+"114",
        //"west" : ELROOMSD+"127",
        
    ]));
}
