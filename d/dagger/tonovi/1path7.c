#include <std.h>
#include "/d/dagger/tonovi/short.h"

inherit ROOM;

void create(){
    ::create();
   set_terrain(HILLS);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("Southern path to Tonovi");
    set_long(
      "You are standing on the top of one of the hills.  You can't make out the wall to the south anymore, but to the east you can see another road leading to a gate in the eastern wall.  To the northwest you can clearly see the city sitting on 3 of the largest hills on the plains.  To the north is a crossroads."
    );
    set_smell("default", "You smell the flowers of the plains");
    set_listen("default", "A cool breeze whispers across the plains");
    set_items( ([
	"hills" : "You are sorrounded by these great majestic green monsters.",
	"road" : "The new road here is just starting to get ruts in it, as is burns an ominous scar across the plains.",
	"wall" : "The great wall around the plain is supposed to keep invaders out, but it looks more like it keeps the beauty in.",
	"tonovi" : "You see the great city like a great wound in the plains.",
      ]) );
    set_exits( ([
	"southwest" : RPATH "1path6",
	"north" : RPATH "crossrd",
      ]) );

}
