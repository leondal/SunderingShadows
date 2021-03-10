#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
	::create();
   set_terrain(GARDEN);
   set_travel(DIRT_ROAD);
	set_property("indoors",0);
	set_property("light",2);
	set_short("A front yard");
	set_long(
	"You are standing in the front yard of someone's house. The lawn"+
	" is kept carefully manicured. The %^BOLD%^%^GREEN%^grass%^RESET%^"+
	" looks lush and healthy. A row of lovely %^YELLOW%^daffodils%^RESET%^"+
	" are planted at the front of the yard. Near the house are some"+
	" carefully trimmed hedges. There is a little worn dirt path that leads"+
	" from the street up to the house."
	);
	set_smell("default","You smell the fresh mountain air.");
	set_listen("default","Everything is peacefully quiet here.");
	set_items(([
	"lawn" : "The lawn is kept carefully manicured.",
	"grass" : "%^BOLD%^%^GREEN%^The grass is a pretty green shade,"+
	" it looks lush and vibrant.",
	"hedges" : "%^GREEN%^Near the front of the house some hedges are"+
	" kept neatly trimmed.",
	({"path","dirt path"}) : "A little worn dirt path leads from the"+
	" street up to the house.",
	"house" : "The house is pretty, one story in height. The"+
	" outside is painted %^BOLD%^white%^RESET%^ and it has a"+
	" %^BOLD%^%^RED%^red%^RESET%^ trim. A few steps lead up to"+
	" the doorway.",
	"door" : "%^BOLD%^A pretty white door leads into the house.",
	({"daffodils","row of daffodils"}) : "%^YELLOW%^A row of pretty"+
	" daffodils are lined up at the front of the yard. They look well"+
	" cared for and are all in a straight line.",
	]));
	set_exits(([
	"north" : ROOMS+"street32",
	"south" : ROOMS+"house7",
	]));
	set_door("door",ROOMS+"house7","south","antioch house key");
	if(query_night() == 1) {
		set_locked("door",1);
	}
}
