#include <std.h>
#include "../area_stuff.h"

inherit EASTOASIS;

void create()
{
    ::create();
    set_exits(([
        "north" : ELROOMSE+"7",
        "east" : ELROOMSE + "5",
        "south" : ELROOMSE + "9",
        "west" : ELROOMSE + "11",
        "tent" : ELROOMS + "leader_tent",
    ]));
}
