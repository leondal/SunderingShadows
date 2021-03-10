#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g61",
	"east" : ROOMS+"e2729",
	"north" : ROOMS+"v72",
	"south" : ROOMS+"v74",
	"southeast" : ROOMS+"v75",
	]) );
}
