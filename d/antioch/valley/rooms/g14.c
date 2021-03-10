#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g15",
	"east" : ROOMS+"g13",
	"north" : ROOMS+"m1",
	"south" : ROOMS+"g9",
	]) );
}
