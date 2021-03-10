#include <std.h>
#include "../area_stuff.h"

inherit EASTOASIS;

void create()
{
    ::create();
    set_exits(([
        "north" : ELROOMSE+"14",
        "east" : ELROOMSE + "10",
        //"south" : ELROOMSE + "15",
        //"west" : ELROOMSE + "1",
        "tent" : ELROOMS+"component_shop",
    ]));
}
