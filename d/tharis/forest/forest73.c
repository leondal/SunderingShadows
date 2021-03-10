//forest73.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "west":TFOREST"forest72",
                "northeast":TFOREST"forest74",
                ]));

}

