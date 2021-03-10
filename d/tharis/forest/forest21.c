//forest21.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southwest":TFOREST"forest20",
                "northwest":TFOREST"forest67a",
                "northeast":TFOREST"forest55",
    ]));
}

