#include <std.h>
inherit ROOM;

void create()  {
    ::create();
   set_terrain(HILLS);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("Path to Kinaro.");
    set_long(
      "As you continue down the foothills along the dagger coastline, you can make out more details of the town below.  It looks to be a small mining village, taking the precious metals from the cliffs along the seacoast."
    );
    set_smell("default", "You can smell the fresh sea air as you descend along the cliffs.");
    set_listen("default", "You can hear the sea below you, and the many seagulls that soar above.");
    set_items(([
	"cliffs" : "One wrong step on these cliffs would mean your death.",
	"sea" : "You can see the magnificent sea below you.",
	"town" : "You can tell this town is not that far distant, but it looks smaller than it should."
      ]));

    set_exits(([
	"northwest" : "/d/dagger/kinaro/path1",
	"southeast" : "/d/dagger/kinaro/path3"
      ]));
}
