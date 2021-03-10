#include <std.h>

inherit "/d/tharis/road/wroad2";

void create(){
	::create();
	set_exits(([
		"east":"/d/tharis/road/wroad16",
          "northwest":"/d/tharis/road/wroad18"
		]));
}
