//eroad10.c

#include <std.h>
#include "../eroad.h"
inherit EROAD;

void create(){
        ::create();
        set_exits(([
                "west":"/d/tharis/road/eroad9",
                "northeast":"/d/tharis/road/eroad11",
        ]));
}
