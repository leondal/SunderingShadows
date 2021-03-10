#include <std.h>
#include "../area_stuff.h"

inherit EASTOASIS;

void create()
{
    ::create();
    set_exits(([
        //"south" : ELROOMSE+"3",
        "west" : ELROOMSE+"9",
        "east" : ELROOMSE+"3",
        "north" : ELROOMSE+"5",
        "tent" : ELROOMS + "general_store",
    ]));
}
