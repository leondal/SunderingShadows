#include <std.h>
#include "/d/dagger/tonovi/short.h"

inherit ROOM;

void create() {
    ::create();
   set_terrain(HILLS);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("Yniam crossroads");
    set_long(
      "You are at the crossroads between the two roads to Tonovi.  The two roads meet in a Y, one to the south and one to the east, and head to the northwest to the city of Tonovi."
    );
    set_listen("default", "A cool breeze whispers across the plains");
    set_smell("default", "You smell the flowers of the plains");

    set_items( ([
	"road" : "This is a new dirt road, just starting to get its ruts.",
      ]) );
    set_exits( ([
	"south" : RPATH "1path7",
	"east" : RPATH "2path5",
	"northwest" : RPATH "road1",
      ]) );

}
