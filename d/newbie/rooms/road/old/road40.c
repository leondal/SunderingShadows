//road40.c

#include <std.h>
#include "../../newbie.h"

inherit ROOM;
inherit "/d/newbie/rooms/inherit/roadrats";

void create() {
    ::create();
    set_property("light",2);
    set_property("no teleport",1);
   set_terrain(SCRUB_LANDS);
   set_travel(PAVED_ROAD);
    set_short("%^BOLD%^A wide gravel trail");
    set_long(
@NEWBIE
You are on a wide trail passing across mostly open land. You can see a forest off in the distance to the northeast. The gravel trail is thin over the hard-packed dirt. To the northwest, you can see what appears to be a town.
NEWBIE
    );
    set_smell("default","You catch a whiff of something disconcerting from the south.");
    set_listen("default","You hear the wind rattling the gate.");
    set_exits(([
       "northwest":ROAD"road41",
       "east":ROAD"road39",
   ]));
}
