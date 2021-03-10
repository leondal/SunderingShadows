#include <std.h>
inherit ROOM;

void create() {
    ::create();
   set_terrain(CITY);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("Before Kinaro");
    set_long(
      "You have completed the dangerous trek down the narrow path, and you have arrived before the town of Kinaro.  The small mining town is smaller than you expected, as it is populated by dwarves."
    );
    set_smell("default", "You can smell the fresh sea air nearby.");
    set_listen("default", "You can hear the gruff voices of dwarves nearby, and of a mining operation in the distance.");
    set_items(([
	"path" : "You feel safer now that you have descended this far.",
	"sea" : "You can just bearly make the sea in the distance.",
	"Town" : "You can see the town of the dwarves just a short distance away.",
	"town" : "You can see the town of the dwarves just a short distance away.",
	"Kinaro" : "You can see the town of the dwarves just a short distance away.",
	"kinaro" : "You can see the town of the dwarves just a short distance away."
      ]));
    set_exits(([
	"northwest" : "/d/dagger/kinaro/path2",
	"east" : "/d/dagger/kinaro/guard1"
      ]));
}
