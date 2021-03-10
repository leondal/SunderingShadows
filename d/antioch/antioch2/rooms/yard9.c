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
	" is kept carefully manicured, but most of it is taken up by"+
	" a large front porch. The porch has a rocking chair and a hammock"+
	" on it. A few steps lead up to the porch and the front door. In"+
	" front of the porch are some carefully trimmed hedges. A little"+
	" worn dirt path leads from the street up to the porch."
	);
	set_smell("default","You smell the fresh mountain air.");
	set_listen("default","Everything is peacefully quiet here.");
	set_items(([
	"lawn" : "The lawn is kept carefully manicured.",
	"grass" : "%^BOLD%^%^GREEN%^The grass is a pretty green shade,"+
	" it looks lush and vibrant. Most of the lawn is taken up by the"+
	" large porch jutting out from the front of the house.",
	"hedges" : "%^GREEN%^Near the front of the porch some hedges are"+
	" kept neatly trimmed.",
	({"path","dirt path"}) : "A little worn dirt path leads from the"+
	" street up to the porch.",
	"house" : "The house is two stories in height and has a large"+
	" porch coming out from the front of it. The porch along with the"+
	" outside of the house is painted %^BOLD%^white%^RESET%^ and it"+
	" has a %^BOLD%^%^MAGENTA%^lavender%^RESET%^ trim. A few steps"+
	" lead up to the porch.",
	"door" : "%^BOLD%^A pretty white door leads into the house.",
	"hammock" : "A simple string hammock is hung from the ceiling of"+
	" the porch. One could sit and swing in it in the cool mountain"+
	" air.",
	({"chair","rocking chair"}) : "A lovely wooden rocking chair sits"+
	" up on the porch. It appears to be hand carved and fit together"+
	" very well. It has obviously had some use by the owner and looks"+
	" very comfortable.",
	"porch" : "%^BOLD%^A large front porch juts out from the front"+
	" of the house. It is painted white and is partially enclosed"+
	" by a lattice work of wood. It is a comfortable place to relax"+
	" in during the day.", 
	]));
	set_exits(([
	"east" : ROOMS+"street32",
	"west" : ROOMS+"house9",
	]));
	set_door("door",ROOMS+"house9","west","antioch house key");
	if(query_night() == 1) {
		set_locked("door",1);
	}
}
