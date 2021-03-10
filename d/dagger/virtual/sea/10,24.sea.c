
#include <std.h>

inherit ROOM;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dockentrance() { return 1; }

void create() {
    set_indoors(1);
    ::create();
    set_property("no teleport",1);
    set_light(2);
     set_property("no teleport",1);
    set_short("In the Dagger Straits");
    set_long(
@OLI
	%^BOLD%^You are on a the Dagger Straits.%^RESET%^
Cliffs mostly surround you. Occassionally you pass a sandbar.
OLI
	);
	set_exits(([
            "east":"/d/shadow/virtual/sea/18,5.sea",
            "west":"/d/dagger/virtual/10,23.sea",
		]));
	
	set_smell("default","You can smell the fresh sea air.");
	set_listen("default","You hear the lapping of waves against the side of the boat.");
}
		
