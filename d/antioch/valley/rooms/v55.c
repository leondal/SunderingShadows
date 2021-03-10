#include <std.h>
#include "../valley.h"
inherit VALLEY1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v54",
	"east" : ROOMS+"g66",
	"north" : ROOMS+"v56",
	"south" : ROOMS+"g67",
	"northwest" : ROOMS+"shore12",
	]) );
}
