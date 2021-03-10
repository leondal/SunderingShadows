#include <std.h>

inherit ROOM;

void create() {
	::create();
	set_property("light", 1);
	set_short("%^RESET%^ORANGE%^The End Of A Dock...%^RESET%^\n");
	set_long(
	this_object()->query_short()+
	"You are at the end of a short, archaic dock. Most of this "
	"rotting pier hangs in the water, while that which still stands "
	"leads north, onto the shore of a forested island. The dock "
	"appears as though it hasn't been used for quite some time. "
	"\n"
	);
	set_items(([
		"dock" : "The dock is in ruins.",
		"pier" : "The dock is in ruins.",
		"water" : "The vast sea expands towards the horizon.",
		"shore" : "A rocky shore lies north.",
		"island" : "The island appears to be a dense forest.",
	]));
	set_exits(([
		"north" : "/d/islands/illusion/shore4",
	]));
}
