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
	"On either side of you are two buildings that have remained somewhat"+
	" standing within the rubble. They aren't in the best of condition,"+
	" but at least they are standing. The street continues to the north"+
	" and south as best it can, littered with rubble and cracks. In the"+
	" far distance you can see the remains of what must once have been a"+
	" large tower."
	);
	set_smell("default","Dust hangs in the air.");
	set_listen("default","The ruins are eerily quiet.");
	set_items(([
	({"streets","street"}) : "The streets have large cracks running through"+
	" them, probably from earthquakes that appear to have shook the entire"+
	" area. Wood from the collapsed houses has fallen into the street in"+
	" places.",
	({"shop","shops","building","buildings"}) : "On either side of the street"+
	" here are two buildings that have remained relatively standing.",
	"tower" : "In the distance to the north is a large tower that has greatly"+
	" crumbled, now standing barely three stories tall.",
	]));
	set_exits(([
	"north" : ROOMS+"ruins8",
	"south" : ROOMS+"ruins4",
	"west" : ROOMS+"ruins6",
	"east" : ROOMS+"ruins7",
	]));
}
