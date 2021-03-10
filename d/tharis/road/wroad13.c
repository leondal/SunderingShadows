#include <std.h>

inherit "/d/tharis/road/wroad2";

void create(){
	::create();
	set_exits(([
		"northeast":"/d/tharis/road/wroad12",
		"southwest":"/d/tharis/road/wroad14",
		"south":"/d/azha/theater/rooms/azp9",
		]));
}
