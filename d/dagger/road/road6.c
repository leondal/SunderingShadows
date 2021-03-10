#include <std.h>
#include "/d/dagger/road/short.h"

inherit ROOM;

void create() {
    ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("The Dagger Sea coast road.");
    set_long(
      "%^CYAN%^You are walking on the road above the Dagger Sea coast cliffs.  To the southwest you can see the town of Muileann in the distance.  To the northeast you can see the outpost city of Tonovi and the towns of Torm and Daggerdale.  To the east you can see over the great cliffs down to the dagger sea."
    );
    set_smell("default", "You can smell the salts of the sea on the cool breeze.");
    set_listen("default", "The sound of the waves on the cliffs below float up to your ears.");
    set_items(([
	"cliffs" : "You can see the ocean below the great granite cliffs",
	"sea" : "The great waves crash against the cliffs hundreds of feet below you.",
      ]));
    set_exits(([
	"northeast" : RPATH "road7",
	"southwest" : RPATH "road5",
      ]));
}
