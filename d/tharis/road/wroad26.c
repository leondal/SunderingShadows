//wroad stuff

#include <std.h>

inherit "/d/tharis/road/wroad2";

void create(){
	::create();
	set_exits(([
		"northeast":"/d/tharis/road/wroad25",
		"west":"/d/tharis/road/wroad27"
		]));
	set_items(([]));

	set_smell("default","The dusty road combines with the fragrances of the forest.");
	set_listen("default","A bird calls, a tree toad chirps, the wind rustles the trees.");

}
