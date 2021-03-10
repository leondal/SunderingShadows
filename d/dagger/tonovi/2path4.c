#include <std.h>
#include "/d/dagger/tonovi/short.h"

inherit ROOM;

void create(){
    ::create();
   set_terrain(HILLS);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("Eastern road to Tonovi");
    set_long(
      "You are on the eastern road across the Yniam plains.  To the south a lookout post sits watching the road.  To the east you can make out the walls fading in the distance, the great gates just a speck in your vision.  From here you can make out a crossroads far to the east."
    );
    set_listen("default", "A cool breeze whispers across the plains");
    set_smell("default", "You smell the flowers of the plains");

    set_items( ([
	"road" : "The new road here is just starting to get ruts in it, as is burns an ominous scar across the plains.",
	"wall" : "The great wall around the plain is supposed to keep invaders out, but it looks more like it keeps the beauty in.",
	({"gateway", "gates"}) : "These gates run through the wall surrounding the plains to protect the security of the town of Tonovi",
	({"lookout post", "post", "lookout"}) : "On the road you can see a brick structure standing aside the road.",
      ]) );

    set_exits( ([
	"west" : RPATH "2path5",
	"east" : RPATH "2path3",
	"south" : RPATH "tower2",
      ]) );

}
