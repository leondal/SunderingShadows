#include <std.h>
#include "/d/dagger/road/short.h"

inherit ROOM;

void create(){
    ::create();
   set_travel(DIRT_ROAD);
   set_terrain(OLD_MOUNTS);
    set_property("light", 2);
    set_short("The Dagger Sea coast road.");
    set_long(
      "%^CYAN%^You are just inland of the beaches of the Dagger Seacoast.  From here you can see the road to the south that leads to the great seaport of Torm.  To the northeast you can see the town of Daggerdale, and to the northwest is the Yniam plains.  To the northeast the road starts to turn inland, and away from the seacoast."
    );
    set_smell("default", "You can smell the salts of the sea on the cool breeze.");
    set_listen("default", "The sound of the waves on the cliffs below float up to your ears.");
    set_items( ([
	"beaches" : "Golden sand lines the beaches along the Dagger Sea.",
	"sea" : "The great waves crash against teh cliffs hundreds of feet below.",
      ]) );
    set_exits( ([
	"southwest" : RPATH "road15",
	"northeast" : RPATH "road17",
	"south" : "/d/dagger/Torm/road/path1",
      ]) );
}

void init(){
    ::init();
    // Calls wandering monster daemon
    RDEMON->startup();
}
