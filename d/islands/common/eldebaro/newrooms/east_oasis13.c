#include <std.h>
#include "../area_stuff.h"

inherit EASTOASIS;

void create()
{
    ::create();
    set_exits(([
       //"north" : ELROOMSE+"12",
        "east" : ELROOMSE + "12",
        "south" : ELROOMSE + "14",
        //"west" : ELROOMSE + "1",
        "tent" : ELROOMS +"bar",
    ]));
}
