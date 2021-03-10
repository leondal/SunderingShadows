//forest154.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "south":TFOREST"forest153",
                "northeast":TFOREST"forest155"
                ]));

}

