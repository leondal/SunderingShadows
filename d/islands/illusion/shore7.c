#include <std.h>

inherit ROOM;

void create() {
	::create();
	set_property("light", 1);
	set_short("%^RESET%^BOLD%^The Southern Shore Of An Island...%^RESET%^\n");
	set_long(
	this_object()->query_short()+
	"You find yourself on the rocky southern-shore of a flourishing "
	"woodland island. The smooth rocks of this beach are inhabited "
	"with numerous sea-faring creatures; such as crabs, starfish, "
	"and various other wonders. The thick forest block any "
	"further travels to the east. "
	"\n"
	);
	set_items(([
		"shore" : "The shore is covered with ocean-sprayed rocks.",
		"beach" : "The shore is covered with ocean-sprayed rocks.",
		"island" : "The island is densely forested.",
		"forest" : "The island is densely forested.",
		"rocks" : "The rocks under your feet are very slippery!",
		"creatures" : "You examine the oddities of the sea.",
		"crabs" : "The crabs scatter as you take notice of them.",
		"starfish" : "These miraculous little things relax in "
			"pools of sea-water.",
		"wonders" : "You examine the oddities of the sea.",
	]));
	set_exits(([
		"west" : "/d/islands/illusion/shore6",
	]));
}
