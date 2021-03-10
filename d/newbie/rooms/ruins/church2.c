//church.c  basement by Styx

#include <std.h>
#include "../../newbie.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light",0);
    set_property("no teleport",1);
	 set_indoors(1);
    set_terrain(WOOD_BUILDING);
    set_travel(RUBBLE);
    set_short("The ruins of a church.");
    set_long("This rather large and deep basement area is also in ruins.  "
"The large stones that form the walls are rather roughly cut and it "
"appears to have been used mostly for storage.  Most of the floor above "
"is intact and there is no light source so it is rather dark.  Partially "
"hidden behind some rotting shelves is an opening in the wall.  Some of "
"the large rocks that used to be the wall of the basement lie broken on "
"the floor around the opening.  You can't help but have a foreboding "
"feeling as you examine the broken out wall.  Perhaps whatever broke "
"through the wall caused the beginning of the downfall of the town."
    );
    set_smell("default","You catch the hint of an ammonia-like and musty smell from the opening.");
    set_listen("default","The wind whistles through the ruins.");
    set_items(([
        "buildings":"Most of the buildings appear to be little more than partial walls left standing.",
        "rubble":"The remains of the stone and wood once used in construction.",
        "opening":"It is large enough to step through and you can make out that there is a large cavern on the other side.  It appears the basement may have been built in one end of the cavern and that wall was made to block it off from the rest.",
		  ({"rocks", "stones", "wall"}):"It appears the wall was broken through from the other side and some of the stones broken and pushed through onto the floor in the process.",
    ]));
    set_exits(([
        "ladder":N_RUINS"church",
        "opening":"/d/newbie/rooms/drow/rooms/dn0",        
    ]));
}