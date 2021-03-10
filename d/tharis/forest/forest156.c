//forest156.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "south":TFOREST"forest157",
                "northwest":TFOREST"forest155"
                ]));

}

