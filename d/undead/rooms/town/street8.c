#include "../../undead.h"
inherit INH+"street";

void create() {
    ::create();
    set_long(::query_long() +"  Within the massive wall east of you lies one of "
"the two main city gates.\n");

    set_exits(([
        "gate":BF"room8",
        "north":TOWN"street7",
        "south":TOWN"street9"
    ]));

    set_door("gate",BF+"room8","gate","open_gate");
    set_open("gate",0);
    set_string("gate","open","The metal gates lift up, allowing you to pass!");
    set_door_description("gate","These massive metal gates are easily twice the "
"height of an average man and almost that wide.  They are built of solid slabs "
"of iron with steel mesh criss-crossing over the front in a lattice design.");
}

void reset() {
    ::reset();
    if(!present("guard")) {
        new(MON"ogre_guard")->move(TO);
        new(MON"ogre_guard")->move(TO);
    }
}
