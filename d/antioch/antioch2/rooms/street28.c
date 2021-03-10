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
	"This is a quiet little road that leads to the residential section"+
	" of Antioch. You can smell the fresh, clean mountain air. To the"+
	" north and south is carefully manicured grass and you can even"+
	" see the trees of the forest in the distance. Up ahead to the"+
	" west are the houses. Back to the east is the gate to Oak Street."
	);
	set_smell("default","You smell the fresh mountain air.");
	set_listen("default","Everything is peacefully quiet here.");
	set_items(([
	({"trees","forest","forest trees"}) : "%^GREEN%^To the north you"+
	" can see the trees of the forest. They are a vibrant green and"+
	" look quiet healthy.",
	"grass" : "%^BOLD%^%^GREEN%^Carefully manicured grass is on either"+
	" side of the road here.",
	"houses" : "To the west are the citizen's houses.",
	({"street","cobblestones","cobbles","road","path"}) : "The"+
	" lane is paved with cobblestones.",
	"street sign" : "This is Holly Lane.",
	]));
	set_exits(([
	"east" : ROOMS+"street27",
	"west" : ROOMS+"street29",
	]));
}
