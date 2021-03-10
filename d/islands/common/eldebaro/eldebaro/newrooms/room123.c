#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        //"north" : ELROOMSD+"52",
        "east" : ELROOMSD+"124",
        //"south" : ELROOMSD+"106",
        "west" : ELROOMSD+"122",
        
    ]));
}
