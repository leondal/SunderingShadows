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
      "You are on the eastern road to the town of Tonovi.  Right now you are standing under the great gates in the eastern wall surrounding the plains of Yniam.  Through the gates you can see the great plains streatch seemingly foever in innocent majesty, their great emerald hills scared by the road that burns its way into the heart of Tonovi."
    );
    set_listen("default", "A cool breeze whispers across the plains");
    set_smell("default", "You smell the flowers of the plains");
    set_items( ([
	"road" : "The new road here is just starting to get ruts in it, as is burns an ominous scar across the plains.",
	"wall" : "The great wall around the plain is supposed to keep invaders out, but it looks more like it keeps the beauty in.",
	({"gateway", "gates"}) : "These gates run through the wall surrounding the plains to protect the security of the town of Tonovi",
      ]) );

    set_exits( ([
	"west" : RPATH "2path3",
	"east" : RPATH "2path1",
	"north" : "/d/player_houses/lusell/rooms/to_tonovi"
      ]) );

}
