#include <std.h>
#include "../theater.h"
inherit CALIM2;
	void create(){ 
	::create();
	set_exits(([ "northwest" : ROOMDIR"cal2",
			 "northeast" : ROOMDIR"cal4",
			]));
}