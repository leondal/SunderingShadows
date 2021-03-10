#include <std.h>
#include "../area_stuff.h"

inherit EASTOASIS;

void create()
{
    ::create();
    set_exits(([
        "north" : ELROOMSE+"13",
        "east" : ELROOMSE + "11",
        "south" : ELROOMSE + "15",
        //"west" : ELROOMSE + "1",
        "tent" : ELROOMS +"portal_room",
    ]));
}
