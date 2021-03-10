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
"%^CYAN%^You are just north of the northern gate to the town of Daggerdale, on the northern Dagger road.  To the north you can make out the Dagger Marsh, to the northeast the tops of the trees of the Kilkean forest are visible, and to the west you can make out the plains of Tonovi."
    );
    set_smell("default", "You can smell the evil as it floats south from the marsh.");
    set_listen("default", "You can hear the hooves of horses on the road.");
    set_items( ([
	"plains" : "These emerald plains span a great distance.",
	({"trees", "forest"}) : "The tops of the great trees of the Kilkean forest are barely visible in the distance.",
      ]) );
    set_exits( ([
	"southwest" : RPATH "road28",
	"northeast" : RPATH "road30",
      ]) );
}
