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
"You have reached a crossroad at the end of this bleak path.  To the southeast the path climbs down over the cliffs.  To the north the path leads towards a huge system of cliffs and volcanos.  You get a strange sense of evil coming from that direction."
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
"west" : RPATH "road109",
"southeast" : "/d/dagger/kinaro/path1",
"north" : "/d/dagger/elements/path/path1",
      ]));
}
