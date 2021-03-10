#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",0);
    set_short("Shadowlord Forest");
    set_terrain(HEAVY_FOREST);
    set_travel(DIRT_ROAD);
    set_long(
@KAYLA
You are standing on a path deep in the heart of the forest.  The
forest is not so dense here.  The path continues northeast deeper
into the forest and south to the worn path.
KAYLA
    );
    set_listen("default","The usual sounds of life are strangely absent.");
    set_exits(([
	"northeast" : "/d/deku/open/dforest8-2",
	"south" : "/d/deku/open/dforest7"
      ] ));
set_items(([
  ] ));
}
