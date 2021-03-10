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
	set_short("%^RESET%^GREEN%^Somewhere In A Dark Forest...%^RESET%^\n");
	set_long(
	this_object()->query_short()+
	"The surrounding forest is a thick congregation of towering "
	"redwood trees, and gangs of thorn-infested bushes. A narrow "
	"dirt path works its way through the woodlands. "
	"\n"
	);
	set_listen("default","You hear whispers within the bushes.\n");
	set_items(([
		"trees" : "These trees spiral several hundred feet high.",
		"bushes" : "Venomous looking bushes surround you.",
		"path" : "This dirt path appears to be untraveled.",
		"woodlands" : "Thick forest surrounds you.",
		"shadows" : "The shadows seem to move.",
	]));
	set_exits(([
	]));
}
