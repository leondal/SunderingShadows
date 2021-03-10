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
      "You are in a dip between two hills as you cross the plains.  All around you all you can see is the majestic green of the plains under the beautiful sky.  The road continues to the north and south."
    );
    set_smell("default", "You smell the flowers of the plains");
    set_listen("default", "A cool breeze whispers across the plains");
    set_items( ([
	"hills" : "You are sorrounded by these great majestic green monsters.",
	"road" : "The new road here is just starting to get ruts in it, as is burns an ominous scar across the plains.",
      ]) );
    set_exits( ([
	"northeast" : RPATH "1path5",
	"south" : RPATH "1path3",
      ]) );

}
