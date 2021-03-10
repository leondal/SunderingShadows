#include <std.h>
#include "../eroad.h"
inherit EROAD;

void create(){
        ::create();
        set_exits(([
                "west":"/d/tharis/road/eroad5",
                "east":"/d/tharis/road/eroad7",
        ]));
}
