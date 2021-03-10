// sea description for Coralsea island

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
There is a raised ridge of coral here at which you may be able to anchor.
OLI
	);
	set_exits(([
		"north":"/d/shadow/virtual/61,8.sea",
		"south":"/d/shadow/virtual/63,8.sea",
		"east":"/d/shadow/virtual/62,9.sea",
		"west":"/d/shadow/virtual/62,7.sea",
		"dock":"/d/shadow/virtual/sea/coralsea.dock"
		]));
	
      set_smell("default","You smell the salty air of the ocean.");
	set_listen("default","You can hear the crashing of waves against the reef.");
}
		
