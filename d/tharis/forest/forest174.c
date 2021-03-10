//forest174.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northeast":TFOREST"forest175",
                "southeast":TFOREST"forest173"
                ]));
    find_object_or_load(TFOREST"forest180");
}

