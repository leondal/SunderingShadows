//forest19.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "west":TFOREST"forest18",
                "northeast":TFOREST"forest20"
                ]));
}

