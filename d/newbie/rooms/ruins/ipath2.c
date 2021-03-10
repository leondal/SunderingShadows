//ipath2.c

#include <std.h>
#include "../../newbie.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain(RUINS);
    set_travel(RUBBLE);
    set_short("The ruins of a town.");
    set_long(
@NEWBIE
You are in the middle of the ruins of former buildings. The rubble is
deep here and you have to climb over and around many obstacles. Stones,
wood, and dirt pave the slight pathway through the ruins. The path here
appears to be more used than in other places throughout the ruins.
NEWBIE
    );
    set_smell("default","The air brings odors from things buried in the rubble.");
    set_listen("default","The wind rattles through the ruined buildings.");
//    set_search("rubble",(:TO,"__Search":));
    set_items(([
        "buildings":"Most of the buildings appear to be little more than partial walls left standing.",
        "rubble":"The remains of the stone and wood once used in construction.",
    ]));
    set_exits(([
        "west":N_RUINS"ipath1",
    ]));
}

int __Search(){

}



