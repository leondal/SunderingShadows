//forest136.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southeast":TFOREST"forest135",
                "northwest":TFOREST"forest137"
                ]));

}

