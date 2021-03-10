#include <std.h>
#include "../area_stuff.h"

inherit EASTOASIS;

void create()
{
    ::create();
    set_exits(([
       //"north" : ELROOMSE+"12",
        "east" : ELROOMSE + "7",
        "south" : ELROOMSE + "11",
        "west" : ELROOMSE + "13",
        "tent" : ELROOMS + "crystal_shop",
    ]));
}
