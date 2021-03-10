// sea description for Shadow dock

#include <std.h>

inherit ROOM;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dockentrance() { return 1; }

void create() {
    set_indoors(1);
    ::create();
    set_light(2);
    set_short("You are on the Dagger Sea.");
     set_property("no teleport",1);
    set_long(
@OLI
        %^BOLD%^You are on the Dagger Sea.%^RESET%^
The city of Torm's dock is here.
OLI
	);
	set_exits(([
		"east":"/d/dagger/virtual/5,2.sea",
		"dock":"/d/shadow/virtual/sea/torm.dock"
		]));
	
     set_smell("default","The smells of the city dock waft from the warf.");
	set_listen("default","You can hear the crashing waves to the east.");
}
		
