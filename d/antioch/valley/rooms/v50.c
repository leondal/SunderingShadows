#include <std.h>
#include "../valley.h"
inherit VALLEY1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v51",
	"east" : ROOMS+"shore5",
	"north" : ROOMS+"shore4",
	"south" : ROOMS+"v44",
	]) );
}
