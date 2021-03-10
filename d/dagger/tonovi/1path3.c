#include <std.h>
#include "/d/dagger/tonovi/short.h"

inherit ROOM;

void create(){
    ::create();
   set_terrain(SCRUB_LANDS);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("Southern path to Tonovi");
    set_long(
      "You are just to the north side of the gateway in the wall sorrounding the plains of Yniam.  You can see the great wall stretch across the plain to a corner in the east, then head north.  To the west the wall ends after about 400 yards.  The road here leads due north across the hills to the town of Tonovi."
    );
    set_smell("default", "You smell the flowers of the plains");
    set_listen("default", "A cool breeze whispers across the plains");
    set_items( ([
	"hills" : "The emerald hills on the Yniam plains almost seem to roll in their beauty and splendor, and would be even more beautiful were it not for the pollution and corruption from the city of Tonovi.",
	"road" : "The new road here is just starting to get ruts in it, as is burns an ominous scar across the plains.",
	({"gateway", "gates"}) : "These gates run through the wall surrounding the plains to protect the security of the town of Tonovi",
      ]) );
    set_exits( ([
	"south" : RPATH "1path2",
	"north" : RPATH "1path4",
      ]) );
}
