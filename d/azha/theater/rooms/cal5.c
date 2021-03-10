#include <std.h>
#include "../theater.h"
inherit CALIM2;
	void create(){ 
	::create();
	set_exits(([ "southwest" : ROOMDIR"cal4",
			 "east" : ROOMDIR"azp1",
			]));
}