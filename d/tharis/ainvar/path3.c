inherit "std/room";

#include <std.h>;

void create() {
	::create();
	set_property("indoors", 0);
	set_property("light", 2);
	set("short", "A path in the woods");
	set("long",
@BAMF
	The forest grows around you as you leave the main road.  Small animals 
dart from tree to tree, and there are birds chirping among the branches.  
The well-worn path continues on towards the east.
BAMF
	);
	set_items(([ 
	"animals" : "Small squirrels chatter as they jump from limb to limb.",
	"birds" : "Birds of vairous color dot the trees as they sing their songs.",
	"path" : "This path has seen the use of thousands of feet over time." 
	]));
	set_exits(([ "west" : "/d/tharis/ainvar/path2",
		     "north" : "/d/tharis/ainvar/forest3",
		     "south" : "/d/tharis/ainvar/forest8",
		"east" : "/d/tharis/ainvar/path4"]));
	set_smell("default", "The sweet scent of the forest lays lightly upon the air.");
	set_listen("default", "The singing of birds and the chittering of small animals fill the air.");
}
