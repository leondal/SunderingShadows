//forest57.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southeast":TFOREST"forest58",
                "northwest":TFOREST"forest56",
                "enter":TFOREST"neutral1"
        ]));
}

