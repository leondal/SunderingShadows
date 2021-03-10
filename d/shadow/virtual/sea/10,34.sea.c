// sea description for Deku island

#include <std.h>

inherit ROOM;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dockentrance() { return 1; }

void create() {
    set_indoors(1);
    ::create();
    set_light(2);
    set_short("You are in the Desert");
    set_property("no teleport",1);
    set_long(
@OLI
	%^BOLD%^You are on a the Saakrune Sea.%^RESET%^
You see an island in the water here.
OLI
	);
	set_exits(([
		"north":"/d/shadow/virtual/9,34.sea",
		"south":"/d/shadow/virtual/11,34.sea",
		"east":"/d/shadow/virtual/10,35.sea",
		"west":"/d/shadow/virtual/10,33.sea",
		"dock":"/d/shadow/virtual/sea/argentrock.dock"
		]));
	
	set_smell("default","You can smell the arid desert air blowing from the west.");
	set_listen("default","You can hear the crashing waves to the east.");
}
		
