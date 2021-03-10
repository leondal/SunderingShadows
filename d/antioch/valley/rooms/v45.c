#include <std.h>
#include "../valley.h"
inherit VALLEY1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v44",
	"east" : ROOMS+"v46",
	"south" : ROOMS+"g81",
	"north" : ROOMS+"shore5",
	]) );
}
