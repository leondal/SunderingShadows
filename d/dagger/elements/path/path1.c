#include <std.h>
#include "/d/dagger/road/short.h"

inherit ROOM;

void create() {
    ::create();
   set_terrain(SCRUB_LANDS);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("Road through Dagger");
    set_long(
"You are on a forboding road leading north.  Brush has been cleared from the path here, allowing further travel to the north."
    );

    set_smell("default", "The smell of the sweat of the horses that have used this road is strong.");
    set_listen("default", "You hear your own footfalls on the stones as well as the hooves of the animals on this road");

    set_items(([
"cliffs" : "There is a path here that leads to the dwarven community of Kinaro.",
"sea" : "The great blue sea is to the south.",
"tree" : "This tree is HUGE!",
"trees" : "Those trees are HUGE!",
      ]));

    set_exits(([
"north" : "/d/player_houses/melic/rooms/mel0",
"south" : "/d/dagger/road/road110"
      ]));
}
