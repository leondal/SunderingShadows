#include <std.h>
#include "../theater.h"
inherit CALIM;
	void create(){ 
	::create();
	set_exits(([ "northeast" : ROOMDIR"calim2",
			 "southeast" : ROOMDIR"calim3",
			 "west" : "/d/azha/town/east4",
		    ]));
}
