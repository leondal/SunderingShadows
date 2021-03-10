#include <std.h>
#include "../theater.h"
inherit CALIM2;
	void create(){ 
	::create();
	set_exits(([ "west" : ROOMDIR"calim8",
			 "northeast" : ROOMDIR"cal2",
			]));
}