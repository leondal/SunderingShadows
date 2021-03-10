//wroad stuff

#include <std.h>

inherit "/d/tharis/road/wroad2";

void create(){
	::create();
	set_exits(([
		"east":"/d/tharis/road/wroad21",
		"west":"/d/tharis/road/wroad23"
		]));
	set_items(([]));
	
	set_smell("default","The dusty road combines with the fragrances of the forest.");
	set_listen("default","A bird calls, a tree toad chirps, the wind rustles the trees.");

}
