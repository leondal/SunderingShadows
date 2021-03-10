#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g30",
	"east" : ROOMS+"m1",
	"north" : ROOMS+"m2",
	"south" : ROOMS+"g15",
	]) );
}
