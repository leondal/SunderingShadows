#include <std.h>
#include "/d/dagger/road/short.h"

inherit ROOM;

void create() {
::create();
   set_terrain(ROCKY);
   set_travel(DIRT_ROAD);
set_property("light", 2);
set_short("The Dagger Sea coast road.");
set_long(
"%^ORANGE%^This is the coast road running along the high cliffs above the Dagger Sea.  To the southwest you can see the evil looking tower of Muileann rising above the city, and to the north you can see the outpost city of Tonovi.  Just a short distance to the northeast you can see a tollbooth."
);
set_smell("default", "You can smell the sea on the light breeze");
set_listen("default", "You can hear the sea crashing against the cliffs below.");

set_items(([
"road" : "Looks rather dusty and rarely used.  Kinda makes you wonder what you're doing here.",
"sea" : "You can see the surf over 50 feet below you over the cliffs to the east.",
"cliffs" : "They are formed of granite and are worn deep by the action of the surf.",
"light" : "It looks like a lantern.",
]));

set_exits(([
"northeast" : RPATH "road2",
"southwest" : "/d/koenig/road/room5",
]));
}
