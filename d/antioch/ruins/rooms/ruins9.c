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
	"You have come to an intersection. This area is relatively clear, though"+
	" it still suffers from cracks and some rubble. To the east is a rather"+
   " large house that has partially collapsed. To the west is a path that"+
	" leads to the graveyard. In the northern distance is a crumbling tower."
	);
	set_smell("default","Dust hangs in the air.");
	set_listen("default","The ruins are eerily quiet.");
	set_items(([
	"tower" : "In the distance to the north is a large tower that has greatly"+
	" crumbled, now standing barely three stories tall.",
	({"street","streets","intersection"}) : "This intersection is relatively"+
	" clear, compared to the rest of the ruins at least. The streets are"+
	" still riddled with cracks and rubble is scattered across the ground.",
	({"house","large house"}) : "To the east you can see a partially collapsed"+
	" house.",
   "path" : "A path to the west leads to the graveyard.",
	]));
	set_exits(([
	"south" : ROOMS+"ruins8",
	"north" : ROOMS+"ruins13",
	"west" : ROOMS+"ruins11",
	"east" : ROOMS+"ruins10",
	]));
}
