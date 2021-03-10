#include <std.h>
#include "/d/dagger/tonovi/short.h"

inherit ROOM;

void create(){
    ::create();
   set_terrain(GRASSLANDS);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("Eastern road to Tonovi");
    set_long(
      "You are on the eastern road of Tonovi, which runs through a long straight section between the emerald hills.  To the east you can see the gateway on the eastern wall.  To the west you can make out a lookout post on the plain next to the road."
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
	"west" : RPATH "2path4",
	"east" : RPATH "2path2",
      ]) );

}
