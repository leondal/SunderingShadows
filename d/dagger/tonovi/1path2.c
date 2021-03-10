#include <std.h>
#include "/d/dagger/tonovi/short.h"

inherit ROOM;

void create() {
    ::create();
   set_terrain(SCRUB_LANDS);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("Southern path to Tonovi");
    set_long(
      "You are on the southern path to Tonovi.  You have just started along the road, and are now in the gateway of the wall that surrounds the entire Yniam plains.  To the north you see the road cross the rolling hills to enter the outpost city of Tonovi.  To the south you can see where the road meets the road crossing above the cliffs of dagger."
    );

    set_items( ([
	"hills" : "The emerald hills on the Yniam plains almost seem to roll in their beauty and splendor, and would be even more beautiful were it not for the pollution and corruption from the city of Tonovi.",
	"road" : "This newly created road burns an ugly scar across the plains towards Tonovi.",
	({"gateway", "gates"}) : "These gates run through the wall surrounding the plains to protect the outer security of the town of Tonovi",
	"cliffs" : "These cliffs drop several hundred feet to the rocky ocean coast.",
      ]) );
    set_exits( ([
	"south" : RPATH "1path1",
"north" : RPATH "1path3",
      ]) );
}
