#include <std.h>
#include "../area_stuff.h"

inherit EASTOASIS;

void create()
{
    ::create();
    set_exits(([
        "north" : ELROOMSE+"8",
        "east" : ELROOMSE + "4",
        //"south" : ELROOMSE + "9",
        "west" : ELROOMSE + "10",
        "tent" : ELROOMS+"weapon_shop",
    ]));
}
