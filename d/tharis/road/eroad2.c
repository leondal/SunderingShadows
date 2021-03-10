#include <std.h>
#include "../eroad.h"
inherit EROAD;

void create(){
        ::create();
        set_exits(([
                "west" : "/d/tharis/newtharis/rooms/egate2.c",
                "east":"/d/tharis/road/eroad3",
        ]));
}
