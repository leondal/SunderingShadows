//road39.c

#include <std.h>
#include "../../newbie.h"

inherit ROOM;
inherit "/d/newbie/rooms/inherit/roadrats.c";

void create() {
    ::create();
    set_property("light",2);
    set_property("no teleport",1);
   set_terrain(SCRUB_LANDS);
   set_travel(PAVED_ROAD);
    set_short("A wide gravel trail");
    set_long(
@NEWBIE
You are on a wide trail passing across mostly open land. You can
see a forest off in the distance to the northeast. The gravel trail
is thin over the hard-packed dirt. To the east, a path crosses this
road. To the northwest, you can see what appears to be a town.
NEWBIE
    );
    set_smell("default","You smell the fresh air of the open land.");
    set_listen("default","You hear a gate rattling in the wind nearby.");
    set_exits(([
       "west":ROAD"road40",
       "east":ROAD"road38",
   ]));
}





