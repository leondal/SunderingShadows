#include <std.h>
#include "/d/dagger/road/short.h"
#include <objects.h>

inherit ROOM;

void create(){
    ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("Road through inner Dagger");
    set_long(
      "%^CYAN%^You are standing at one of the crossroads through Dagger.  Here on the road you can go north, towards the Dagger Marsh, to the east, where the road curves back towards the seacoast, or southwest, towards Daggerdale, and the Yniam plains."
    );
    set_smell("default", "You can smell the evil as it floats south from the marsh.");
    set_listen("default", "You can hear the hooves of horses on the road.");
    set_items( ([
	"plains" : "These emerald plains span a great distance.",
	({"trees", "forest"}) : "The tops of the great trees of the Kilkean forest are barely visible in the distance.",
      ]) );
    set_exits( ([
	"north" : RPATH "road41",
	"southwest" : RPATH "road39",
	"east" : RPATH "road81",
      ]) );
}

void reset(){
    ::reset();
    RDEMON->startup();
}

