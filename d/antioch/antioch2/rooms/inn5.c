#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
	::create();
   set_travel(DIRT_ROAD);
   set_terrain(WOOD_BUILDING);
	set_property("indoors",1);
	set_property("light",2);
	set_short("%^BOLD%^Hallway of the White Dragon Inn");
	set_long(
	"You are at the end of a small hallway on the second floor of"+
	" the %^BOLD%^White Dragon Inn%^RESET%^. The hallway continues"+
	" to the west and you see a set of spiral stairs leading down"+
	" to the first floor. There are three doors here, the one on"+
	" the east seems to lead to a bathroom and you can smell the"+
	" fragrance of scented soaps drifting out from beneath the door."+
	" On the north is an oak door with an oak leaf engraved into it."+
	" Across from that is a door that has been painted a dark blue"+
	" shade. A lush %^GREEN%^green carpet%^RESET%^ covers the floor"+
	" here, muffling footsteps so the guests can sleep peacefully."+
	" Oil lamps are spaced out along the walls to provide light."
	);
	set_smell("default","The faint smell of scented soaps drifts out"+
	" from the bathroom.");
	set_listen("default","It is peacefully quiet here.");
	set_items(([
	({"carpet","lush carpet","green carpet"}) : "%^GREEN%^A thick"+
	" green carpet covers the floor, muffling the sounds of people"+
	" passing by.",
	({"lamps","lamp","oil lamps"}) : "Oil lamps are hung at intervals"+
	" along the walls here to help light the hallway.",
	"door" : "This is the door to the bathroom.",
	"blue door" : "This door is on the southern wall and is painted"+
	" a dark blue shade.",
	"oak door" : "The door is on the northern wall and is made of"+
	" oak with an oak leaf intricately engraved on it.",
	"oak leaf" : "An intricately carved oak leaf is engraved on the"+
	" northern door.",
	({"stairs","stair case"}) : "Further down the hallway there is"+
	" a large stair case.",
	]));
	set_exits(([
	"west" : ROOMS+"inn4",
	"north" : ROOMS+"oak_room",
	"south" : ROOMS+"blue_room",
	"east" : ROOMS+"bathroom",
	]));
	set_door("oak door",ROOMS+"oak_room","north",0);
	set_door("blue door",ROOMS+"blue_room","south",0);
   set_door("door",ROOMS+"bathroom","east",0);
}
