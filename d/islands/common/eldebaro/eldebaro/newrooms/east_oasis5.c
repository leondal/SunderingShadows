#include <std.h>
#include "../area_stuff.h"

inherit EASTOASIS;

void create()
{
    ::create();
    set_exits(([
        "north" : ELROOMSE+"6",
        "east" : ELROOMSE + "2",
        "south" : ELROOMSE + "4",
        "west" : ELROOMSE + "8",
        "tent" : ELROOMS+"healer_shop",
    ]));
}
