#include <std.h>
#include "/d/dagger/tonovi/short.h"

inherit ROOM;

void create() {
    ::create();
   set_terrain(SCRUB_LANDS);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("Path to Tonovi.");
    set_long(
      "You are on the beginning of the path to the city of Tonovi.  Tread with care."
    );
    set_smell("default", "You smell the sweat of the animals as they labor on the roads.");
    set_listen("default", "You can hear people working on the roads.");
    set_items(([
	"this" : "it looks like that",
      ]));
    set_exits(([
	"east" : "/d/dagger/road/road28",
	"west" : "/d/dagger/tonovi/2path2",
      ]));
}
