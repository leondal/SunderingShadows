//forest95.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southwest":TFOREST"forest94",
                "north":TFOREST"forest96",
                ]));
}

