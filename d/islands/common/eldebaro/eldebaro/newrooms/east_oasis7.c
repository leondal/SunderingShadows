#include <std.h>
#include "../area_stuff.h"

inherit EASTOASIS;

void create()
{
    ::create();
    set_exits(([
        //"north" : ELROOMSE+"6",
        "east" : ELROOMSE + "6",
        "south" : ELROOMSE + "8",
        "west" : ELROOMSE + "12",
        "tent" : ELROOMS+"armor_shop",
    ]));
}
