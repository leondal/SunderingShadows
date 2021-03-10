#include <std.h>
#include "../theater.h"
inherit CALIM2;
	void create(){ 
	::create();
	set_exits(([ "southwest" : ROOMDIR"cal3",
			 "northeast" : ROOMDIR"cal5",
			]));
}