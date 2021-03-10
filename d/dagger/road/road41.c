#include <std.h>
#include "/d/dagger/road/short.h"

inherit ROOM;

void create(){
    ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("Northern Dagger road");
    set_long(
      "%^CYAN%^You are standing at the southern end of the northern extension of the Dagger Road.  From here, you can see the main road to the south, and to the northwest you can see a dark path leading into the Dagger Marsh.  To the north the road winds into the mountains, and to the east is the Kilkean Forest."
    );
    set_smell("default", "You can smell the evil as it floats south from the marsh.");
    set_listen("default", "You can hear the hooves of horses on the road.");
    set_items( ([
	"marsh" : "The marsh to the west is covered by an evil dark cloud.",
	({"trees", "forest", "kilkean"}) : "To the east you can see the great trees of the Kilkean Forest.",
      ]) );
    set_exits( ([
	"north" : RPATH "road42",
	"south" : RPATH "road40",
"northwest" : "/d/dagger/marsh/marsh1",
      ]) );
}

