//forest81.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southwest":TFOREST"forest80",
                "northeast":TFOREST"forest82",
                ]));
}

