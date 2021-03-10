#include <std.h>

inherit ROOM;

void init() {
	::init();
	if(this_object()->is_player() == 0) {
	}
}

void create() {
	::create();
	set_property("light", 1);
	set_short("%^RESET%^GREEN%^The Entrance To A Forest...%^RESET%^\n");
	set_long(
	this_object()->query_short()+
	"The surrounding forest is a thick congregation of towering "
	"redwood trees, and gangs of thorn-infested bushes. A narrow "
	"dirt path works its way through the woodlands, heading north "
	"and south. To the south you hear the sounds of waves, and the "
	"north is consumed by shadows. "
	"\n"
	);
	set_listen("default","You hear whispers within the bushes.\n");
	set_items(([
		"trees" : "These trees spiral several hundred feet high.",
		"bushes" : "Venomous looking bushes surround you.",
		"path" : "This north-south path appears to be untraveled.",
		"woodlands" : "Thick forest surrounds you.",
		"shadows" : "The shadows extend from the north.",
	]));
	set_exits(([
		"north" : "/d/islands/illusion/forest1",
		"south" : "/d/islands/illusion/shore4",
	]));
}
