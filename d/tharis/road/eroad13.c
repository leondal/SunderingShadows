//eroad13.c

#include <std.h>
#include "../eroad.h"
inherit EROAD;

void create(){
        ::create();
        set_exits(([
                "northwest":"/d/tharis/road/eroad12",
                "northeast":"/d/tharis/road/eroad14",
        ]));
}
