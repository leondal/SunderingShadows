#include <std.h>
#include "../ruins.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(RUINS);
   set_travel(DIRT_ROAD);
	set_property("indoors",0);
	set_property("light",1);
	set_short("%^BOLD%^%^BLACK%^Desolate Ruins%^RESET%^");
	set_long(
	"This was once the main street through town, now it is interrupted in"+
	" places by cracks. The streets are charred in places and wood from the shops has"+
	" fallen across the road in places. On the west is a collapsed bar."+
	" A sign with a large picture of a mug of ale is on the ground."+
	" The double doors have broken in half underneath the weight of"+
	" the collapsed walls and roof. In the northern distance is a"+
	" crumbling tower."
	);
	set_smell("default","Dust hangs in the air.");
	set_listen("default","The ruins are eerily quiet.");
	set_items(([
	({"streets","street"}) : "The streets have large cracks running through"+
	" them, probably from earthquakes that appear to have shook the entire"+
	" area. Wood from the collapsed houses has fallen into the street in"+
	" places.",
	({"crumbled bar","bar"}) : "On the west is what is left of the"+
	" bar. The roof caved in in the center, and the walls have collapsed"+
	" inwards as well. The sign that once hung above the door has fallen"+
	" to the ground, and the large double doors have been split in half"+
	" from the weight of the rest of the building.",
	"sign" : "A sign with a picture of a large mug of ale is on the"+
	" ground here.",
	({"doors","double doors"}) : "The large double doors that once lead"+
	" into the bar have broken in half due to the weight of the roof"+
	" and the walls upon them.",
	"tower" : "In the distance to the north is a large tower that has greatly"+
	" crumbled, now standing barely three stories tall.",
	]));
	set_exits(([
	"north" : ROOMS+"ruins15",
	"south" : ROOMS+"ruins13",
	]));
}
