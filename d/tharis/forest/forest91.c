//forest91.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "west":TFOREST"forest90",
                "east":TFOREST"forest92",
                ]));
}

