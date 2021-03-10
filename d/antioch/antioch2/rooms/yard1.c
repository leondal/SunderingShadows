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
	" looks lush and healthy. There is a lovely %^BOLD%^%^MAGENTA%^pink%^RESET%^"+
	" rose bush on the eastern side of the lawn. Near the front of the"+
	" house are some carefully trimmed hedges. There is a little worn"+
	" dirt path that leads from the street up to the house."
	);
	set_smell("default","You smell the scent of roses.");
	set_listen("default","Everything is peacefully quiet here.");
	set_items(([
	"lawn" : "The lawn is kept carefully manicured.",
	"grass" : "%^BOLD%^%^GREEN%^The grass is a pretty green shade,"+
	" it looks lush and vibrant.",
	"hedges" : "%^GREEN%^Near the front of the house some hedges are"+
	" kept neatly trimmed.",
	({"rosebush","rose bush","pink rose bush"}) : "On the eastern part"+
	" of the lawn a %^BOLD%^%^MAGENTA%^pink%^RESET%^ rose bush that"+
	" is growing rapidly, with many roses on it.",
	({"roses","pink roses"}) : "%^BOLD%^%^MAGENTA%^Beautiful pink"+
	" roses are growing all over the rosebush. They smell lovely and"+
	" are quite large.",
	({"path","dirt path"}) : "A little worn dirt path leads from the"+
	" street up to the house.",
	"house" : "The house is a quaint little one story cottage. The"+
	" outside is painted %^YELLOW%^yellow%^RESET%^ with a %^BOLD%^white%^RESET%^"+
	" trim. A few steps lead up to the doorway.",
	"door" : "%^YELLOW%^A pretty yellow door leads into the house.",
	]));
	set_exits(([
	"south" : ROOMS+"street29",
	"north" : ROOMS+"house1",
	]));
	set_door("door",ROOMS+"house1","north","antioch house key");
	if(query_night() == 1) {
		set_locked("door",1);
	}
}
