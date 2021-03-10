#include <std.h>
#include "/d/dagger/road/short.h"

inherit ROOM;

void create(){
    ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("The Dagger Sea coast road.");
    set_long(
      "%^CYAN%^You are on the dagger seacoast road just northeast of the bridge, visible to the southwest crossing the river Shelk.  To your east you can see the golden beaches as they line the seacoast.  To the northwest is the great Yniam plains, and to the northeast you can make out the spires above the seaport of Torm."
    );
    set_smell("default", "You can smell the salts of the sea on the cool breeze.");
    set_listen("default", "The sound of the waves on the cliffs below float up to your ears.");
    set_items( ([
	"beaches" : "Golden sand lines the beaches along the Dagger Sea.",
	"sea" : "The great waves crash against teh cliffs hundreds of feet below.",
      ]) );
    set_exits( ([
	"southwest" : RPATH "bridge",
	"northeast" : RPATH "road14",
      ]) );
}
