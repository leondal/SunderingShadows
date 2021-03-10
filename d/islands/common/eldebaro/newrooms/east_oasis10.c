#include <std.h>
#include "../area_stuff.h"

inherit EASTOASIS;

void create()
{
    ::create();
    set_exits(([
        "north" : ELROOMSE+"11",
        "east" : ELROOMSE + "9",
        //"south" : ELROOMSE + "9",
        "west" : ELROOMSE + "15",
        "tent" : ELROOMS+"church",
    ]));
}
