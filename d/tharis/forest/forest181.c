//forest181.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southeast":TFOREST"forest182",
              "out":"/d/tharis/conforest/rooms/f78",
                "west":TFOREST"forest180"
        ]));
    find_object_or_load(TFOREST"forest182");
    find_object_or_load(TFOREST"forest180");

}

