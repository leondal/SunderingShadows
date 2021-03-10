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
	" looks lush and healthy. On either side of the lawn are gardenia"+
	" bushes. Several gardenias are in bloom, giving off a lovely"+
	" fragarance. Near the front of the house are some carefully"+
	" trimmed hedges. A little worn dirt path leads from the"+
	" street up to the house."
	);
	set_smell("default","You smell the lovely scent of gardenias.");
	set_listen("default","Everything is peacefully quiet here.");
	set_items(([
	"lawn" : "The lawn is kept carefully manicured.",
	"grass" : "%^BOLD%^%^GREEN%^The grass is a pretty green shade,"+
	" it looks lush and vibrant.",
	"hedges" : "%^GREEN%^Near the front of the house some hedges are"+
	" kept neatly trimmed.",
	({"path","dirt path"}) : "A little worn dirt path leads from the"+
	" street up to the house.",
	"house" : "The house is a quaint one story cottage. The"+
	" outside is painted %^BOLD%^%^MAGENTA%^pink%^RESET%^ and it has a"+
	" %^BOLD%^%^RED%^rose%^RESET%^ trim. A few steps lead up to"+
	" the doorway.",
	"door" : "%^BOLD%^A pretty pink door leads into the house.",
	({"gardenia","gardenias","gardenia bushes","gardenia bush"}) : "On"+
	" either side of the lawn are gardenia bushes. Lovely %^BOLD%^white%^RESET%^"+
	" gardenias are in bloom on them. The bushes seem quite healthy.",
	]));
	set_exits(([
	"south" : ROOMS+"street31",
	"north" : ROOMS+"house5",
	]));
	set_door("door",ROOMS+"house5","north","antioch house key");
	if(query_night() == 1) {
		set_locked("door",1);
	}
}
