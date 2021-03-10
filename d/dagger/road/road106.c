#include <std.h>
#include "/d/dagger/road/short.h"

inherit ROOM;

void create() {
    ::create();
   set_terrain(ROCKY);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("Road through Dagger");
    set_long(
"You are on a rocky path through dagger headed back towards the sea, as the coastline turns back north.  You can see the trees of the Kilkean forest to the northwest.  Otherwise there is nothing on this seldom traveled rocky path."
    );

    set_smell("default", "The smell of the sweat of the horses that have used this road is strong.");
    set_listen("default", "You hear your own footfalls on the stones as well as the hooves of the animals on this road");

    set_items(([
"forest" : "The great forest spreads out to the northwest",
"sea" : "The great blue sea is to the south.",
"tree" : "This tree is HUGE!",
"trees" : "Those trees are HUGE!",
      ]));

    set_exits(([
"west" : RPATH "road105",
"east" : RPATH "road107",
      ]));
}
