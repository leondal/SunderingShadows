//	The Royal Southern Road
//	Thorn@Shadowgate
//	10/2/94
//	Darkwood forest
//	road10
/*Updated by Circe 10/4/03 to include room name, smell, listen and to use inherits to save on memory. Also, a few rooms were added to fix the way the area looks when mapped.*/

#include <std.h>

inherit "/d/darkwood/room/road8.c";
inherit DAEMON;

void create() {
    ::create();
    set_long(
"%^GREEN%^You are on the road entering a dark forest. The lightof the sun is almost blotted out by the near-perfect shade of the treesall round you. The thick growth of bushes beneath the trees looks as thought it might be hiding any number of unsavory creatures. A coolbreeze suddenly chills you to the bone. A breeze of the unnatural sort....
"
    );
    set_exits(
              (["north" : "/d/darkwood/room/road9",
                "south" : "/d/darkwood/room/road11",]) );

}

void init() {
	::init();
	call_out("sway", 10);
}

int sway() {
      tell_room(TO,"The tree branches sway in the wind.");
	return 1;
}
