#include <std.h>
#include "../area_stuff.h"

inherit EASTOASIS;

void create()
{
    ::create();
    set_exits(([
        //"north" : ELROOMSE+"6",
        "east" : ELROOMSE + "1",
        "south" : ELROOMSE + "5",
        "west" : ELROOMSE + "7",
        "tent" : ELROOMS+"stables",
    ]));
}
