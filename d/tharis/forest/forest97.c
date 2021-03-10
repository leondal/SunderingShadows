//forest97.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southeast":TFOREST"forest96",
                "northeast":TFOREST"forest98",
                ]));
}

