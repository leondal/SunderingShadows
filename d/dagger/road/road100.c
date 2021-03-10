#include <std.h>
#include "/d/dagger/road/short.h"

inherit ROOM;

void create() {
    ::create();
   set_terrain(ROCKY);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
set_short("Eastern Dagger Road");
    set_long(
"You have reached the crossroads on the eastern Dagger road.  To the east the path becomes rockier and leads back towards the sea.  To the southwest the road leads past the Kilkean forest towards Daggerdale."
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
"west" : RPATH "road99",
"east" : RPATH "road101",
      ]));
}
