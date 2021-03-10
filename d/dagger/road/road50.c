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
      "%^CYAN%^You are traveling the northern extension of the dagger road.  To the east you can make out the trees of the Kilkean forest, and to the west an evil cloud hangs over the Dagger Marsh.  To the north the mountains of dagger rise above the horizon, you can see them clearer now as you get closer."
    );
    set_smell("default", "You can smell the evil as it floats south from the marsh.");
    set_listen("default", "You can hear the hooves of horses on the road.");
    set_items( ([
	"marsh" : "The marsh to the west is covered by an evil dark cloud.",
	({"trees", "forest", "kilkean"}) : "To the east you can see the great trees of the Kilkean Forest.",
	"mountains" : "You can see the snow peaked mountains rise above the lands of dagger, cutting off the arctic northern wastes.  %^BLUE%^You can feel an evil flowing from them from here.%^RESET%^",
      ]) );
    set_exits( ([
	"south" : RPATH "road49",
	"northwest" : "/d/dagger/keep/road/road1",
      ]) );
}

void init(){
    ::init();
    // Calls wandering monster daemon
    RDEMON->startup();
    }
