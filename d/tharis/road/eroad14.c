//eroad14.c

#include <std.h>
#include "../eroad.h"
inherit EROAD;

void create(){
        ::create();
        set_exits(([
                "southwest":"/d/tharis/road/eroad13",
                "east":"/d/tharis/road/eroad15",
        ]));
}
