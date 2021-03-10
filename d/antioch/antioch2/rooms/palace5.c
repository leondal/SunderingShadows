#include <std.h>
#include "../antioch.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_short("Guard Post");
	set_long(
	"This is a guard post on the second floor of the Antioch palace. A flight"+
	" of stone steps leads up to this room. There isn't much here, really,"+
	" just a small wooden table with a few chairs. A pitcher of refreshing"+
	" water is on the table, along with several glasses for the guards to"+
	" drink from. A plate has been set out with slices of bread and cheese."+
	" In the eastern corner is a barrel full of arrows and a rack of extra"+
	" swords and some shields. Oil lamps are fixed to the walls of the room"+
	" to provide light. Hanging down from the arched ceiling is a large bell"+
	" with a rope attached. The guards can ring the bell to sound the alarm,"+
	" alerting the rest of the city to an attack."
	);
	set_smell("default","You can smell the cheese on the table.");
	set_listen("default","The wind whistles along the walls outside.");
	set_items(([
	"floor" : "The floor is made of the same dun colored bricks as the rest"+
	" of the palace. Some dirt has been tracked in by the patroling guards"+
	" and it could stand to be swept.",
	"ceiling" : "From the ceiling hangs a large iron bell that can be sounded"+
	" by the guards as an alarm to the rest of the city.",
	"bell" : "A large bell is hanging from the ceiling. A rope is attached to"+
	" the striker in the center of the bell, hanging down for the guards to"+
	" be able to ring if there is trouble.",
	"rope" : "A thick rope is attached to the center of the bell. It hangs"+
	" down in easy reach for the guards to be able to pull if there is an"+
	" emergency.",
	({"lamp","lamps","oil lamps","oil lamp"}) : "Oil lamps are attached to"+
	" the walls, shedding light on the room.",
	({"wall","walls"}) : "The walls are made from dun colored bricks and are"+
	" completely barren.",
	({"table","wooden table"}) : "A plain wooden table has been placed on"+
	" the western side of the room. A pitcher of water along with some"+
	" glasses and a plate of bread and cheese are on top of it. Some chairs"+
	" are near it for the guards to rest on a moment.",
	({"chair","chairs"}) : "A few wooden chairs have been placed around the"+
	" table.",
	"pitcher" : "A pitcher of cool refreshing water is on top of the table.",
	({"glass","glasses"}) : "There are several glasses on the table for the"+
	" guards to fill with water and drink from.",
	"plate" : "A plate of sliced cheese and bread sits on top of the table"+
	" for the guards to snack on.",
	({"cheese","bread","sliced cheese","sliced bread"}) : "Slices of wheat"+
	" bread and goat's cheese are on a plate for the guards to snack on.",
	({"stairs","flight of stairs"}) : "A flight of stairs spirals up to this"+
	" room, coming up by the northern wall.",
	]));
	set_exits(([
	"south" : ROOMS+"palace4",
	"down" : ROOMS+"guard2",	
	]));
}
