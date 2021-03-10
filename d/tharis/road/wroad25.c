//wroad stuff

#include <std.h>

inherit "/d/tharis/road/wroad2";

void create(){
	::create();
	set_exits(([
		"southeast":"/d/tharis/road/wroad24",
//           "north":"/d/tharis/barrow/rooms/bd1",
            "north" : "/d/tharis/cemetery/kpath",
		"southwest":"/d/tharis/road/wroad26"
		]));
	set_items(([]));

	set_smell("default","The dusty road combines with the fragrances of the forest.");
	set_listen("default","A bird calls, a tree toad chirps, the wind rustles the trees.");

}
