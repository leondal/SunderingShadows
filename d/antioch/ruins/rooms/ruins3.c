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
	" places by cracks. The shops that were on either side of the street"+
	" here have collapsed, it looks as though earthquakes shook the city."+
	" A few rocks from the stone wall have bounced into the street here."
	);
	set_smell("default","Dust hangs in the air.");
	set_listen("default","The ruins are eerily quiet.");
	set_items(([
	({"streets","street"}) : "The streets are littered with stones"+
	" that have crashed to the ground when the great wall fell. There"+
	" are also charred sections from mage fire that was directed, or"+
	" reflected, here. Large cracks run across the street in places, it seems"+
	" as though earthquakes racked the city.",
	({"stones","wall","walls","stone"}) : "The walls around the city"+
	" have crumbled and some of the stones have crashed down into the streets"+
	" here.",
	({"shop","shops"}) : "The shops on either side of the street have collapsed"+
	" into heaps of wood.",
	]));
	set_exits(([
	"north" : ROOMS+"ruins4",
	"south" : ROOMS+"fountain",
	]));
}
