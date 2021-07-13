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
      "%^CYAN%^You are traveling the northern dagger road, just north of the town of Daggerdale.  To the south you can make out the town quite well.  To the west is the Yniam plains, and to the northeast you can make out the tops of the trees in the Kilkean forest.  To the north you can see the black clouds over the Dagger Marsh.  A narrow pathway leads to the southeast, heading around the ruined walls of Daggerdale towards a large pentagonal building of red stone."
    );
    set_smell("default", "You can smell the evil as it floats south from the marsh.");
    set_listen("default", "You can hear the hooves of horses on the road.");
    set_items( ([
	"plains" : "These emerald plains span a great distance.",
	({"trees", "forest"}) : "The tops of the great trees of the Kilkean forest are barely visible in the distance.",
      ]) );
    set_exits( ([
	"southwest" : RPATH "road36",
	"northeast" : RPATH "road38",
    "southeast" : RPATH"p1"
      ]) );
}
void reset()
{
    ::reset();
    if(!present("street_light",TO))
        new("/d/common/obj/misc/street_light")->move(TO);
}
