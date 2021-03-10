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
There is something interesting in the water here.
OLI
	);
	set_exits(([
		"north":"/d/shadow/virtual/64,35.sea",
		"south":"/d/shadow/virtual/66,35.sea",
		"east":"/d/shadow/virtual/65,36.sea",
		"west":"/d/shadow/virtual/65,34.sea",
		"dock":"/d/shadow/virtual/sea/fall.dock"
		]));
	
	set_smell("default","You can smell the salty sea air blowing from the west.");
	set_listen("default","You can hear the crashing waves to the east.");
}
		
