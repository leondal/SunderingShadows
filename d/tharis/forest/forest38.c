//forest38.c

#include <std.h>
#include "./forest.h"

inherit NFOREST;

void create(){
    ::create();
    set_exits(([
                "north":TFOREST"forest70",
                "south":TFOREST"forest37",
                "east":TFOREST"forest43",
                "up":TFOREST"up5"

                ]));
    set_invis_exits(({"up"}));
    find_object_or_load(TFOREST"up5");

}

void reset(){
    ::reset();

    if(!present("crazed") && random(5) < 3)
   new("/d/tharis/monsters/crazed")->move(TO);
}
