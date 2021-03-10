//#include "short.h"
#include "/d/dagger/road/short.h"
inherit TOLLROOM;
void create()
{
    ::create();
    set_exits(([
        "east" : RPATH "tollbooth2",
        "northeast" : RPATH "road3",
        "southwest" : RPATH "road2",
    ]));
//    set_pre_exit_functions(({"southwest"}),({"go_through_toll"}));
}
void reset() {
    ::reset();
//  if(!present("human guard")) {
//         new(MPATH "dummy")->move(this_object());
//    }
}

