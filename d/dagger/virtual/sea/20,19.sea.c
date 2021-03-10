//sea entrance to Raider's Cove

#include <std.h>

inherit ROOM;

int is_virtual(){return 1;}
int is_water(){return 1;}
int is_dockentrance(){return 1;}

void create(){
	set_indoors(1);
	::create ();
	set_light(2);
	set_short("You are on the Dagger Sea.");
	set_property("no teleport",1);
	set_long("%^BOLD%^You are on the Dagger Sea.%^RESET%^\n"+
		"There is a cove with a dock here.\n"
	);
	set_exits(([
		"north" : "/d/dagger/virtual/19,19.sea",
		"west" : "/d/dagger/virtual/20,18.sea",
		"dock" : "/d/shadow/virtual/sea/raiders.dock"
	]));
	set_smell("default","You can smell the the salty sea air spraying "+
		"in your face.");
	set_listen("default","You can hear the crashing of the waves to the east.");
}