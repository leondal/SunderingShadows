//wroad stuff

#include <std.h>

inherit "/d/tharis/road/wroad2";

void create(){
	::create();
	set_exits(([
		"northeast":"/d/tharis/road/wroad13",
		"west":"/d/tharis/road/wroad15"
		]));
}
