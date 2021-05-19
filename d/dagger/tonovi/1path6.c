#include <std.h>
#include "/d/dagger/tonovi/short.h"

inherit ROOM;

void create(){
    ::create();
   set_terrain(GRASSLANDS);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("Southern path to Tonovi");
    set_long(
      "You are next to the lookout post.  A door to its interior is to the west.  The road continues to the southwest and northeast.  To the northeast you think you can see where the road joins another."
    );
    set_smell("default", "You smell the flowers of the plains");
    set_listen("default", "A cool breeze whispers across the plains");
    set_items( ([
	"hills" : "You are sorrounded by these great majestic green monsters.",
	"road" : "The new road here is just starting to get ruts in it, as is burns an ominous scar across the plains.",
	"wall" : "The great wall around the plain is supposed to keep invaders out, but it looks more like it keeps the beauty in.",
	({"lookout post", "post", "lookout"}) : "On the road you can see a brick structure standing aside the road.",
      ]) );
    set_exits( ([
	"northeast" : RPATH "1path7",
	"southwest" : RPATH "1path5",
	"west" : RPATH "tower1",
      ]) );

}
