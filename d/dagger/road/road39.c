#include <std.h>
#include "/d/dagger/road/short.h"

inherit ROOM;

void create(){
    ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("Road through inner Dagger");
    set_long(
      "%^CYAN%^You are near a crossroads on the roads through dagger.  To the southwest you can see the town of daggerdale.  To the northeast you can make out the trees of the Kilkean forest as they mesh with the Yniam plains, just to the east of where the northern dagger road cuts through the plain.  To the northwest, you can see the dark clouds over the Dagger Marsh."
    );
    set_smell("default", "You can smell the evil as it floats south from the marsh.");
    set_listen("default", "You can hear the hooves of horses on the road.");
    set_items( ([
	"plains" : "These emerald plains span a great distance.",
	({"trees", "forest"}) : "The tops of the great trees of the Kilkean forest are barely visible in the distance.",
      ]) );
    set_exits( ([
	"southwest" : RPATH "road38",
	"northeast" : RPATH "road40",
      ]) );
}
