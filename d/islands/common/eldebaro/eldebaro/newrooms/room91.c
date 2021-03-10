#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        //"north" : ELROOMSD+"52",
        "east" : ELROOMSD+"92",
        //"south" : ELROOMSD+"22",
        "west" : ELROOMSD+"90",
        
    ]));
}
