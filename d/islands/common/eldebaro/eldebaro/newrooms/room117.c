#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        //"north" : ELROOMSD+"129",
        "east" : ELROOMSD+"118",
        //"south" : ELROOMSD+"101",
        "west" : ELROOMSD+"116",
        
    ]));
}
