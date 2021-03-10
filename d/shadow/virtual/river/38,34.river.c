// sea description for Shadow dock

#include <std.h>

inherit ROOM;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dockentrance() { return 1; }

void create() {
   ::create();
   set_light(2);
   set_short("Dock at Tharis");
   set_property("no teleport",1);
   set_long("%^ORANGE%^Dock at Tharis on the Sarcosta "
	"River%^BLUE%^\nThe road north from Tharis to Shadow crosses "
	"the river here.  This busy dock serves the city of "
	"Tharis merchants as well as some coming from the north.  "
	"Many of the travelers seem to be merchants "
	"or caravans carrying trade goods.\n");
   set_exits(([
	"west":"/d/shadow/virtual/river/38,33.river",
	"east" : "/d/shadow/virtual/river/38,35.river",
	"dock":"/d/shadow/virtual/river/tharis.dock"
   ]));
   set_smell("default","Various scents from the city waft on the breeze.");
   set_listen("default","Sounds of the city and travelers drown out the sounds of nature here.");
}