
//Master Room for all in Shadow city to inherit.

#include <std.h>

inherit ROOM;

void create(){
	::create();
	set_short("Shadow City Inherit");
	set_long("All rooms in Shadow City Inherit this one");
}