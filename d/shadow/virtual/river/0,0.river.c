// river description for Shadow dock

#include <std.h>

inherit ROOM;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dockentrance() { return 1; }

void create() {
   ::create();
   set_light(2);
   set_short("Sarcosta River");
   set_property("no teleport",1);
   set_long("%^CYAN%^You are on a the north branch of the Sarcosta "
	"River%^RESET%^\nYou see the dock on the road west of Shadow "
	"here.  The light forest gives way somewhat to what appears "
	"to be a quiet road leading east and west.  Mountains lie to "
	"the north and the melting snows and runoff no doubt keep "
	"the river flowing well year-round.  The river is too narrow "
	"and treacherous for ferries to go further enough north "
	"to find any other points worth docking at, so this is their "
	"last stop going north.\n");
   set_exits(([
	"south":"/d/shadow/virtual/river/1,0.river",
	"dock":"/d/shadow/virtual/river/shadow.dock"
   ]));
   set_smell("default","You smell the flowers and lush grasses of the Meadowlands to the west.");
   set_listen("default","You hear the bustle of people at the docks and along the road.");
}