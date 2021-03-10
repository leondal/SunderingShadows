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
	"and various other wonders. An opening leads north through the forest. "
	"\n"
	);
	set_items(([
		"shore" : "The shore is covered with ocean-sprayed rocks.",
		"opening" : "There appears to be a path to the north.",
		"beach" : "The shore is covered with ocean-sprayed rocks.",
		"island" : "The island is densley forested.",
		"rocks" : "The rocks under your feet are very slippery!",
		"creatures" : "You examine the oddities of the sea.",
		"crabs" : "The crabs scatter as you take notice of them.",
		"starfish" : "These miraculous little things relax in "
			"pools of sea-water.",
		"wonders" : "You examine the oddities of the sea.",
	]));
	set_exits(([
		"north" : "/d/islands/illusion/forest_entrance",
		"south" : "/d/islands/illusion/dock",
		"east" : "/d/islands/illusion/shore5",
		"west" : "/d/islands/illusion/shore3",
	]));
	new("/d/islands/illusion/monster/oldman")->move(this_object());
}
