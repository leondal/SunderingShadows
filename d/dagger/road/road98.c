#include <std.h>
#include "/d/dagger/road/short.h"

inherit ROOM;

void create() {
    ::create();
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("Road through Dagger");
    set_long(
"You have begun walking along the south edge of the great forest of Kilkean.  The trees in this forest start small, but they grow rapidly, and by the end of their growth period, they can grow to sizes of hundreds of feet and as large around as entire city blocks.  To the far south you can barely make out the sea in the distance."
    );

    set_smell("default", "The smell of the sweat of the horses that have used this road is strong.");
    set_listen("default", "You hear your own footfalls on the stones as well as the hooves of the animals on this road");

    set_items(([
"forest" : "The great forest spreads out to the north",
"sea" : "The great blue sea is to the south.",
"tree" : "This tree is HUGE!",
"trees" : "Those trees are HUGE!",
      ]));

    set_exits(([
"southwest" : RPATH "road97",
"northeast" : RPATH "road99",
      ]));
}
