#include <std.h>
inherit ROOM;

void create()
{
	::create();
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
	set_property("indoors",0);
	set_property("light",2);
	set_property("no sticks",1);
	set_short("On top of the palace walls");
	set_long(
	"You are standing on top of the palace walls. Everything is made out of"+
	" dun colored bricks that are brushed over with mortar and light red"+
	" clay to keep the wind out. The tops of the walls have been designed"+
	" with the idea of defense in mind. The tops of the walls reach high,"+
	" but a large brick is missing from the top every other pace, like most"+
	" normal castles. The corners are more built up with small towers and"+
	" slits for guards to fire arrows out of. This place seems well defended."
	);
	set_smell("default","You can smell the fresh mountain air.");
	set_listen("default","You hear the footsteps of the patrolling guards.");
	set_items(([
	({"bricks","brick","dun colored bricks"}) : "The palace is made out of"+
	" massive dun colored bricks that are brushed over with light red clay"+
	" and mortar to create a flat surface that also keeps the wind out.",
	({"wall","walls"}) : "The palace walls have been designed with the"+
	" obvious idea of defense in mind. They are very sturdy and look to be"+
	" more than adequate protection from invaders.",
	"slits" : "There are slits in the corner towers and along the regular"+
	" walls for archers to fire arrows through behind safe cover.",
	({"tower","towers","corner","corners"}) : "The corners of the walls are"+
	" built up into miniature towers. From there archers can rain down"+
	" flights of arrows upon the would-be invaders under safe cover.",
	"floor" : "The floor is well worn from the patrols of the guards and is"+
	" a bit dusty.",
	]));
}
