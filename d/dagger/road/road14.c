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
      "%^CYAN%^You are on the Dagger Seacoast road.  To the northwest you can see the emerald hills of the Yniam plains.  To the northeast you can see the seaport of Torm growing large on the horizon.  To the east are the golden beaches of the dagger seacoast."
    );
    set_smell("default", "You can smell the salts of the sea on the cool breeze.");
    set_listen("default", "The sound of the waves on the cliffs below float up to your ears.");
    set_items( ([
	"beaches" : "Golden sand lines the beaches along the Dagger Sea.",
	"sea" : "The great waves crash against teh cliffs hundreds of feet below.",
      ]) );
    set_exits( ([
	"northeast" : RPATH "road15",
	"southwest" : RPATH "road13",
      ]) );
}
