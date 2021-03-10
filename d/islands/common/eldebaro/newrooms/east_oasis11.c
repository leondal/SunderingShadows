#include <std.h>
#include "../area_stuff.h"

inherit EASTOASIS;

void create()
{
    ::create();
    set_exits(([
        "north" : ELROOMSE+"12",
        "east" : ELROOMSE + "8",
        "south" : ELROOMSE + "10",
        "west" : ELROOMSE + "14",
        "tent" : ELROOMS + "herb_shop",
    ]));
}
