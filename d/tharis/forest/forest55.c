//forest55.c

#include <std.h>
#include "./forest.h"

inherit GFOREST;

object ranger;
void create(){
    ::create();
    set_exits(([
                "southwest":TFOREST"forest21",
                "southeast":TFOREST"forest56",
                "northeast":TFOREST"forest83",
                "up":TFOREST"up7"

                ]));
    set_invis_exits(({"up"}));
    find_object_or_load(TFOREST"up7");
}

void reset(){
    ::reset();

    if(!present("crazed") && random(5) < 3)
   new("/d/tharis/monsters/crazed")->move(TO);
    if(!objectp(ranger)) {
        ranger = new (MONS"vranger");
        ranger->move(TO);
    }
}
