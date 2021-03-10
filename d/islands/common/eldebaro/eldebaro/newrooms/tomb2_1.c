#include <std.h>
#include "../area_stuff.h"

inherit TOMBHALL;

void create()
{
    ::create();
    set_exits(([
        "north" : ELROOMST + "2_2",
        //"south" : ELROOMST+"1_2",       
    ]));
}
