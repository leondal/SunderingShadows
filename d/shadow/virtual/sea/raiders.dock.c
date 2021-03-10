//dock to Raider's Cove
#include <std.h>

inherit DOCK;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dock() { return 1; }

void create() {
    	::create();
    	set_indoors(0);
    	set_property("no teleport",1);
    	set_light(2);
  	set_terrain(BARREN);
  	set_travel(DECAYED_FLOOR);
	set_short("Raiders Cove");
	set_long("%^RESET%^"+
		"You have come upon a small rundown dock. The dock itself is "+
		"made of old logs and is %^BOLD%^%^WHITE%^painted white%^RESET%^, "+
		"although much of the paint has since chipped away. A small "+
		"matching %^ORANGE%^wooden hut %^RESET%^serves as the "+
		"harbormaster's office. Beyond the dock is a small dirt path "+
		"leading into a lightly wooded area. You cannot see far into "+
		"the trees as the forest grows thicker with distance.");
	set_exits(([
		"northwest" : "/d/player_houses/daelmas/rooms/dp5"
	]));
	set_smell("default","You can smell the rotted wood and sea.");
	set_listen("default","The waves break against the store and dock "+
		"and at times you can hear a sailor yelling.");
}