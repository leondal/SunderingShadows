#include <std.h>
#include "../antioch.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(CITY);
   set_travel(DIRT_ROAD);
	set_property("indoors",0);
	set_property("light",2);
	set_short("Holly Lane");
	set_long(
	"You are on Holly Lane.\n"+
	"This is a little cobbled lane that leads to the residential"+
	" section of Antioch. To the north are the palace walls. A large"+
	" gate is back to the east, it separates the houses from the rest"+
	" of the city and can be locked during times of trouble to keep"+
	" the citizens a bit safer."
	);
	set_smell("default","You smell the fresh mountain air.");
	set_listen("default","Everything is peacefully quiet here.");
	set_items(([
	({"gate","large gate"}) : "A large gate is back to the east, it can"+
	" be locked to help protect the citizens of Antioch from invading"+
	" forces.",
	({"palace","walls","palace walls"}) : "The thick walls of the"+
	" palace are on the north. They look very sturdy and rise up two"+
	" stories. You can see the guards carefully patrolling the walls"+
	" on top.",
	({"street","cobblestones","cobbles","road","path"}) : "The"+
	" lane is paved with cobblestones.",
	"street sign" : "This is Holly Lane.",
	]));
	set_exits(([
	"east" : ROOMS+"street26",
	"west" : ROOMS+"street28",
	]));
}
