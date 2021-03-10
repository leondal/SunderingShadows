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
      "%^CYAN%^You are on the end of the cliffs of dagger.  To the east you can see where the cliffs end, and turn into the beach.  To the northeast you can see the bridge crossing the river Shelk."
    );
    set_smell("default", "You can smell the salts of the sea on the cool breeze.");
    set_listen("default", "The sound of the waves on the cliffs below float up to your ears.");
    set_items( ([
	"cliffs" : "You can see the ocean below the great granite cliffs.",
	"sea" : "The great waves crash against teh cliffs hundreds of feet below.",
      ]) );
    set_exits( ([
	"southwest" : RPATH "road10",
	"northeast" : RPATH "bridge",
      ]) );
}

void reset() {
   ::reset();
}
