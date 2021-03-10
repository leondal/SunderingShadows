#include <std.h>
#include "../cleric.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("indoors",1);
	set_property("no teleport",1);
	set_property("light",3);
	set_short("%^BOLD%^Basement of Antioch's Church");
	set_long(
	"This is the entrance of the cleric's guild that is beneath"+
	" Antioch's Grand Church. Stone steps lead up towards the southern"+
	" wall where you can see into the above room. This room is rather"+
	" plain, more of an entrance way into the guild than anything"+
	" useful. To the north you can see a posting board and a sitting"+
	" room beyond that. To the east is a room with a fountain and"+
	" vials of what looks to be holy water."
	);
	set_smell("default","The room smells faintly of lemons.");
	set_listen("default","Everything is silent down here.");
	set_items(([
	({"stairs","steps","stone steps","stone stairs"}) : "These stone"+
	" stairs lead up into Antioch's Grand Church.",
	"floor" : "The cold stone floor looks very clean.",
	"ceiling" : "The ceiling is made of flat stones that have been"+
	" fit together perfectly.",
	({"stone","stones"}) : "Large gray stones make up the entire"+
	" church. They fit together perfectly, allowing nothing through.",
	]));
	set_exits(([
	"up" : "/d/antioch/antioch2/rooms/church2",
	"north" : ROOMS+"cleric2",
	"east" : ROOMS+"cleric6",
	]));
}
