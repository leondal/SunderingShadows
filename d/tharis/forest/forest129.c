//forest129.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northeast":TFOREST"forest130",
                "west":TFOREST"forest128",
                ]));

}

