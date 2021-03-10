//church.c

#include <std.h>
#include "../../newbie.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain(RUINS);
    set_travel(RUBBLE);
    set_short("The ruins of a church.");
    set_long(
@STYX
You've stepped into the ruins of the town's church which was built just in front of a rather steep hill beyond.  It appears to have been a grand building with some of the oak pews and a large altar still somewhat intact.  Symbols of various clergy are scattered about.  Unlike the other buildings, this one has a basement, perhaps having been intended for safety in a storm.  The stairs to both the upper floor and the basement have fallen in but oddly enough there is a ladder leading into the basement.  Enough of the walls and upper floor remains to keep out much of the outdoor light and there are no other light sources.
STYX
    );
    set_smell("default","The air brings odors from things buried in the rubble.");
    set_listen("default","The wind whistles through the ruins.");
    set_items(([
      "rubble":"The remains of the stone and wood once used in construction.",
      "symbols":"Symbols and paintings of the various gods that the townspeople might have either worshiped or wished to placate are scattered about.",
		"altar":"The altar appears to have had the symbols of many gods carved into the hard oak wood.  The thick stone top is cracked and chipped but appears to have had indentations for offerings, some showing signs of scorch marks from something having been burned in them."
    ]));
    set_exits(([
        "east":N_RUINS"wroad4",
        "ladder":N_RUINS"church2",
    ]));
}