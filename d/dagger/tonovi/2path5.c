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
      "You are on the east road of the Yniam plains.  From here you can start to make out the city to the northwest, whereas the wall is barely visible on the eastern horizon.  Just to the east you can see a lookout post, and to the west you can see a crossroads where the road meets with the southern Tonovi road."
    );
    set_listen("default", "A cool breeze whispers across the plains");
    set_smell("default", "You smell the flowers of the plains");

    set_items( ([
	"road" : "The new road here is just starting to get ruts in it, as is burns an ominous scar across the plains.",
	"wall" : "The great wall around the plain is supposed to keep invaders out, but it looks more like it keeps the beauty in.",
	({"lookout post", "post", "lookout"}) : "On the road you can see a brick structure standing aside the road.",
      ]) );

    set_exits( ([
	"east" : RPATH "2path4",
	"west" : RPATH "crossrd",
      ]) );

}
