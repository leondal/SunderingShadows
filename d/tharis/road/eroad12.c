//eroad12.c

#include <std.h>
#include "../eroad.h"
inherit EROAD;

void create(){
        ::create();
        set_exits(([
                "west":"/d/tharis/road/eroad11",
                "southeast":"/d/tharis/road/eroad13",
        ]));
}
