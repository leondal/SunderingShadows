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
	" looks lush and healthy. Growing up the side of the house is a"+
	" vine of %^BOLD%^white%^RESET%^ roses. Near the base of the house"+
	" are some carefully trimmed hedges. There is a little worn dirt path that"+
	" leads from the street up to the house."
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
	"house" : "The house is quite lovely, two stories in height. The"+
	" outside is painted %^GREEN%^%^BOLD%^mint%^RESET%^ and it has a"+
	" %^GREEN%^forest green%^RESET%^ trim. A few steps lead up to"+
	" the doorway.",
	"door" : "%^BOLD%^A mint green door leads into the house.",
	({"roses","white roses","vine of roses","rose vine"}) : "%^BOLD%^A"+
	" lovely vine of white roses has climbed all the way up to the"+
	" second story of the house. It almost covers it, but it looks"+
	" very charming.",
	]));
	set_exits(([
	"south" : ROOMS+"street30",
	"north" : ROOMS+"house4",
	]));
	set_door("door",ROOMS+"house4","north","antioch house key");
	if(query_night() == 1) {
		set_locked("door",1);
	}
}
