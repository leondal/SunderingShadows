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
	"This is the end of the lane. To the west, north, and south are"+
	" citizen's houses. It is very quiet here, far away from the"+
	" hustle and bustle of the city. The air is crisp and clean and a"+
	" slight breeze is blowing along the lane."
	);
	set_smell("default","You smell the fresh mountain air.");
	set_listen("default","Everything is peacefully quiet here.");
	set_items(([
	({"street","cobblestones","cobbles","road","path"}) : "The"+
	" lane is paved with cobblestones.",
	"street sign" : "This is Holly Lane.",
	"houses" : "There are houses all around you.",
	]));
	set_exits(([
	"east" : ROOMS+"street31",
	"west" : ROOMS+"yard9",
	"north" : ROOMS+"yard8",
	"south" : ROOMS+"yard7",
	]));
}
