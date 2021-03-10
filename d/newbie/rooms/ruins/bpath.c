//bpath.c

#include <std.h>
#include "../../newbie.h"

// inherit ROOM;  changing to have the chances of finding something on search a little wider spread *Styx* 1/12/04, last change 10/19/01

inherit N_RUINS"magic";

void create() {
    ::create();
/*    set_property("light",3);
    set_property("no teleport",1);
    set_terrain(RUINS);
    set_travel(RUBBLE);
    set_short("The ruins of a town.");
*/
    set_long(
@NEWBIE
You are in the middle of the ruins of former buildings.  The rubble is
deep here and you have to climb over and around many obstacles.  Stones,
wood, and dirt pave the slight pathway through the ruins.  It appears
that the walls and former contents of what looks like was once a shop 
to the north are mingled in with the rubble here.
NEWBIE
    );
/*
    set_smell("default","The air brings odors from things buried in the rubble.");
    set_listen("default","The wind rattles through the ruined buildings.");
    set_items(([
        "buildings":"Most of the buildings appear to be little more than partial walls left standing.",
        "rubble":"The remains of the stone and wood once used in construction.",
    ]));
*/
    set_exits(([
        "north":N_RUINS"magic",
        "southwest":N_RUINS"bar2",
    ]));
}





