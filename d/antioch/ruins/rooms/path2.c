#include <std.h>
#include "../ruins.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(HEAVY_FOREST);
   set_travel(DIRT_ROAD);
	set_property("indoors",0);
	set_property("light",2);
	set_short("Road through the woods");
	set_long(
	"You're walking on a road that once lead to the city of Antioch. On both"+
   " sides of the road you see an impenetrable forest. You can see the"+
	" ruins of Antioch to the far west.\n"
	);
	set_smell("default","You smell fresh flowers.");
	set_listen("default","The wind howls through the trees.");
	set_search("default","You find nothing special.");
	set_search("bushes","You search the bushes but you find nothing interesting.");
	set_items(([
	"flowers" : "It seems as if they have grown here forever.",
	({"tree","trees"}) : "The branches of the trees sway in the wind.",
	"branches" : "They look too high to climb.",
	"road" : "It's made of nice looking stones.",
	"bushes" : "They look very harmless to you.",
	({"ruins","ruins of Antioch"}) : "The ruins are to the far west.",
	]));
	set_exits(([
	"west" : ROOMS+"path1",
	"east" : "/d/antioch/wild/forest/forest_entr1",
	]));
}

