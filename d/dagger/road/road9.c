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
      "%^CYAN%^You are on the road along the seacoast of dagger.  To the southwest you can see where Muileann tower peeked over the cliffs just a moment before, but now it has disapeared below the horizon.  To the north you can see the wide Yniam plains.  To the northeast you can see Torm and Daggerdale.  To the east you can see over the cliffs down to the sea, which is getting closer as the cliffs start to level out as you travel northeast."
    );
    set_smell("default", "You can smell the salts of the sea on the cool breeze.");
    set_listen("default", "The sound of the waves on the cliffs below float up to your ears.");
    set_items( ([
	"cliffs" : "You can see the ocean below the great granite cliffs.",
	"sea" : "The great waves crash against teh cliffs hundreds of feet below.",
      ]) );
    set_exits( ([
	"southwest" : RPATH "road8",
	"northeast" : RPATH "road10",
      ]) );
}
