#include <std.h>
#include "../area_stuff.h"

inherit TOMBHALL;

void create()
{
    ::create();
    set_exits(([
        "south" : ELROOMST+"1_2"
    ]));
}
