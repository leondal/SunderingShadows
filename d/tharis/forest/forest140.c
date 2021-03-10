//forest140.c

#include <std.h>
#include "./forest.h"

inherit EFOREST;

void create(){
    ::create();
    set_exits(([
                "northwest":TFOREST"forest151",
                "northeast":TFOREST"forest150",
                "south":TFOREST"forest139",
                "up":TFOREST"up25"

                ]));
    set_invis_exits(({"up"}));
    find_object_or_load(TFOREST"up24");

}


void reset(){
    ::reset();
    if(!present("crazed") && random(5)  < 3)
        new("/d/tharis/monsters/crazed")->move(TO);

}

