#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
	::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_short("%^BOLD%^Hallway of the White Dragon Inn");
	set_long(
	"You are at the top of a stair case in a hallway on the second"+
	" floor of the %^BOLD%^White Dragon Inn%^RESET%^. The hallway"+
	" continues to the east and everything here is covered by the"+
	" same type of thick %^GREEN%^green carpet%^RESET%^ as down stairs."+
	" There are three doors here. The northern door is made of cherry"+
	" and engraved with a large rose on it. To the west is a door"+
	" made of pine wood with the image of a lilac carved into it."+
	" The last door has been painted a dark %^GREEN%^green%^RESET%^"+
	" shade that matches the carpet, it leads to the south. Oil lamps"+
	" are spaced out along the walls to give light to the hallway."
	);
	set_smell("default","A pleasant lemony smell is in the air.");
	set_listen("default","It is peacefully quiet here.");
	set_items(([
	({"carpet","green carpet","thick carpet"}) : "%^GREEN%^The same"+
	" thick green carpet as down stairs covers this hallway.",
	({"lamp","oil lamps","lamps"}) : "Oil lamps are hung on the walls"+
	" here to give light to the hallway.",
	({"stairs","stair case"}) : "The stairs are in the center of the"+
	" room and they spiral downwards. They're made of a dark colored"+
	" wood and are highly polished with a lemony scented cleaner. A"+
	" wide railing is there for safety.",
	"hallway" : "This is a short hallway on the second floor of the"+
	" %^BOLD%^White Dragon Inn%^RESET%^. You can see it end shortly"+
	" to the east.",
	"doors" : "There are three doors here.",
	({"cherry door","rose door"}) : "%^RED%^A large door made of cherry wood"+
	" is on the northern wall. It has a large and very realistic"+
	" image of a rose chiseled onto it.",
	"rose" : "%^BOLD%^%^RED%^The delicate image of a rose is engraved on the northern"+
	" door.",
	({"pine door","lilac door"}) : "%^MAGENTA%^%^BOLD%^This door is on the western side"+
	" and is made of pine wood. On the front a lilac has been carved"+
	" into it in breath taking detail.",
	"green door" : "%^GREEN%^The southern door is painted green, the"+
	" exact same shade as the carpet.",
	]));
	set_exits(([
	"down" : ROOMS+"inn1",
	"south" : ROOMS+"green_room",
	"west" : ROOMS+"lilac_room",
	"north" : ROOMS+"rose_room",
	"east" : ROOMS+"inn5",
	]));
	set_door("green door",ROOMS+"green_room","south",0);
	set_door("rose door",ROOMS+"rose_room","north",0);
	set_door("lilac door",ROOMS+"lilac_room","west",0);
}
