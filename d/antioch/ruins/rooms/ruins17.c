#include <std.h>
#include "../ruins.h"
inherit ROOM;

void create()
{
	::create();
   set_travel(DIRT_ROAD);
   set_terrain(RUINS);
	set_property("indoors",0);
	set_property("light",1);
	set_short("%^BOLD%^%^BLACK%^Desolate Ruins%^RESET%^");
	set_long(
	"This was once the town square. People used to gather here, browsing"+
	" through the vendor shops and chatting. Most of the street has"+
	" been completely ripped to pieces, there is not even a clear"+
	" path through the rubble to the north. The streets here have been"+
	" scorched completely black, not just in a few places. Splinters"+
	" of wood from the vendors shops can be found just about everywhere."+
	" The center of the battle must have been near here. To the north"+
	" is a crumbling tower, but you see no way to reach it. It appears"+
	" that most of the tower collapsed onto the main square."
	);
	set_smell("default","Dust hangs in the air.");
	set_listen("default","The ruins are eerily quiet.");
	set_items(([
	({"streets","street"}) : "The streets here have been razed by the"+
	" earthquakes and completely blackened by mage fire. Splinters of"+
	" wood from the vendor shops that used to occupy this area are"+
	" all over the place. Huge bricks from the tower have fallen all"+
	" over the town square, blocking the streets completely in many"+
	" places.",
	"tower" : "To the north is the remains of what must have once been"+
	" a large tower. Now it is about two stories in height, and it"+
	" appears as though the upper portion of the tower collapsed onto"+
	" the town square, blocking anyone from reaching it.",
	]));
	set_exits(([
	"west" : ROOMS+"ruins15",
	"north" : ROOMS+"ruins18",
	]));
}
