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
    set_short("Near the docks of Dallyh");
     set_property("no teleport",1);
    set_long(
@OLI
	%^BOLD%^You are on a the Saakrune Sea.%^RESET%^
You see an island in the water here.
OLI
	);
	set_exits(([
          "north" : "/d/shadow/virtual/12,22.sea",
           "south" : "/d/shadow/virtual/14,22.sea",
            "east" : "/d/shadow/virtual/13,23.sea",
            "west" : "/d/shadow/virtual/13,21.sea",
             "dock":"/d/shadow/virtual/sea/dallyh.dock",
		]));
	
	set_smell("default","You can smell the arid desert air blowing from the west.");
	set_listen("default","You can hear the crashing waves to the east.");
}
		
