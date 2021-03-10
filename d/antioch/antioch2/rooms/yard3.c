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
	" looks lush and healthy. A healthy row of  %^BOLD%^%^RED%^geraniums%^RESET%^"+
	" are planted near the front of the house. A little worn dirt"+
	" path leads from the street up to the house."
	);
	set_smell("default","You smell the fresh mountain air.");
	set_listen("default","Everything is peacefully quiet here.");
	set_items(([
	"lawn" : "The lawn is kept carefully manicured.",
	"grass" : "%^BOLD%^%^GREEN%^The grass is a pretty green shade,"+
	" it looks lush and vibrant.",
	({"path","dirt path"}) : "A little worn dirt path leads from the"+
	" street up to the house.",
	"house" : "The house is a cute little log cabin. The outside has"+
	" been painted with varnish that makes the wood seem brighter,"+
	" it will also help it to last longer. A few steps lead up to"+
	" the doorway.",
	"door" : "%^BOLD%^A pine wood door leads into the house.",
	({"geraniums","row of geraniums"}) : "%^BOLD%^%^RED%^A row of"+
	" pretty red geraniums is planted at the front of the house.",
	]));
	set_exits(([
	"north" : ROOMS+"street30",
	"south" : ROOMS+"house3",
	]));
	set_door("door",ROOMS+"house3","south","antioch house key");
	if(query_night() == 1) {
		set_locked("door",1);
	}
}
