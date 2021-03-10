// sea description for Shadow dock

#include <std.h>

inherit ROOM;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dockentrance() { return 1; }

void create() {
   ::create();
   set_light(2);
   set_short("Dock at Tabor");
   set_property("no teleport",1);
   set_long("%^ORANGE%^Dock at Tabor on the Sarcosta "
	"River\n%^CYAN%^The bustling dock that serves the city of "
	"Tabor connects to the Northern Highway at the river "
	"here.  You can see numerous travelers on the road.  Many "
	"seem to be merchants or caravans carrying trade goods.\n");
   set_exits(([
	"northwest":"/d/shadow/virtual/river/29,9.river",
	"south" : "/d/shadow/virtual/river/31,11.river",
	"dock":"/d/shadow/virtual/river/tabor.dock"
   ]));
   set_smell("default","Various scents from the city waft on the breeze.");
   set_listen("default","Sounds of the city and travelers drown out the sounds of nature here.");
}