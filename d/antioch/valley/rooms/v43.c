#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v42",
	"east" : ROOMS+"g81",
	"north" : ROOMS+"v44",
	"south" : ROOMS+"g83",
	]) );
}
