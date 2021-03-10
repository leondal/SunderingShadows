//forest20.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southwest":TFOREST"forest19",
                "northeast":TFOREST"forest21"
                ]));
}

