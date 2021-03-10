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
    set_short("Saakrune Sea");
     set_property("no teleport",1);
    set_long(
@OLI
	%^BOLD%^You are on a the Saakrune Sea.%^RESET%^
     Here is a small cove with a dock in it.
OLI
	);
	set_exits(([
		"north":"/d/shadow/virtual/54,0.sea",
		"south":"/d/shadow/virtual/56,0.sea",
		"east":"/d/shadow/virtual/55,1.sea",
        "dock":"/d/shadow/virtual/sea/pirate.dock"
		]));
	
	set_smell("default","You can smell the arid desert air blowing from the west.");
	set_listen("default","You can hear the crashing waves to the east.");
}
		
