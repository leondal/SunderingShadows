//wroad stuff

#include <std.h>

inherit "/d/tharis/road/wroad2";

void create(){
	::create();
	set_exits(([
		"east":"/d/tharis/road/wroad14",
		"west":"/d/tharis/road/wroad16"
		]));
}

reset() {
        ::reset();
        "/d/azha/daemon/overseer"->setup_monsters(TO, "patrol");
}
