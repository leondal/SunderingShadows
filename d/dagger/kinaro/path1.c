#include <std.h>
inherit ROOM;

void create()  {
    ::create();
   set_terrain(HILLS);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("Path to Kinaro.");
    set_long(
      "You have begun your descent down the treacherous foothills that line the cliffs along the dagger coastline.  You can see far in the distance, below you and to the southeast, a town between the cliffs and the sea."
    );
    set_smell("default", "You can smell the fresh sea air as you descend along the cliffs.");
    set_listen("default", "You can hear the sea below you, and the many seagulls that soar above.");
    set_items(([
	"cliffs" : "One wrong step on these cliffs would mean your death.",
	"sea" : "You can see the magnificent sea below you.",
	"town" : "You can tell this town is not that far distant, but it looks smaller than it should."
      ]));

    set_exits(([
"northwest" : "/d/dagger/road/road110",
	"southeast" : "/d/dagger/kinaro/path2"
      ]));
}
