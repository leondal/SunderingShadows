//wroad stuff

#include <std.h>

inherit "/d/tharis/road/wroad2";;

void create(){
	::create();
	set_exits(([
		"east":"/d/tharis/road/wroad3",
                "west":"/d/tharis/road/wroad5",
                "south":"/d/avatars/nienne/dragonlair/clearing"
		]));
}
