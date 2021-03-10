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
	"This was once the entrance to the city of Antioch. Now the stones"+
	" from the walls are scattered about the streets, some have"+
	" already crumbled. There is a large depression in the center of"+
	" the street here, as though a monument or statue once stood in"+
	" that spot, but now it is gone. The streets have charred sections"+
	" from where they have been blasted. A great battle must have taken"+
	" place here to have left the whole city in ruins."
   );
	set_smell("default","Dust hangs in the air.");
	set_listen("default","The ruins are eerily quiet.");
	set_items(([
	({"streets","street"}) : "The streets are littered with stones"+
	" that have crashed to the ground when the great wall fell. There"+
	" are also charred sections from mage fire that was directed, or"+
	" reflected, here. In the center of the street is a large depression"+
	" where some sort of monument must have stood.",
	({"stones","wall","walls","stone"}) : "The walls around the city"+
	" have crumbled, the stones have crashed down into the streets."+
	" You would not have wanted to be here when the stone walls fell.",
	"depression" : "There is a large depression in the middle of the"+
	" street. A fountain or statue must once have stood in that spot"+
	" but it has been purposely removed, nothing the remains of it.",
	]));
	set_exits(([
	"west" : ROOMS+"ruins1",
	"east" : ROOMS+"ruins2",
	"north" : ROOMS+"ruins3",
	"south" : ROOMS+"gates",
	]));
}
