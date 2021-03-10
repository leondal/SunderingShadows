#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m5",
	"east" : ROOMS+"g39",
	"north" : ROOMS+"m15",
	"south" : ROOMS+"g36",
	]) );
}
