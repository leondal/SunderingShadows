//forest50.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southeast":TFOREST"forest51",
                "northwest":TFOREST"forest49",
                ]));
}

