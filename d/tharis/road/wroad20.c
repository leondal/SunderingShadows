//wroad stuff

#include <std.h>

inherit "/d/tharis/road/wroad2";

void create(){
	::create();
	set_exits(([
		"east":"/d/tharis/road/wroad19",
//		"northeast" : "/d/dagger/Elvanta/forest/roompath1",
		"west":"/d/tharis/road/wroad21"
		]));
}
