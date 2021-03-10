#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        //"north" : ELROOMSD+"129",
        "east" : ELROOMSD+"116",
        //"south" : ELROOMSD+"22",
        "west" : ELROOMSD+"114",
        
    ]));
}
