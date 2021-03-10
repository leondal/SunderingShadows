#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v82",
	"south" : ROOMS+"e2128",
	]) );
	set_invis_exits(({"west","south"}));
}

