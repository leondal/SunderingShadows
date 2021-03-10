//forest24.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northwest":TFOREST"forest23",
                "southeast":TFOREST"forest25",
                "northeast":TFOREST"forest44"
    ]));
}
