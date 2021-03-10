#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m15",
	"east" : ROOMS+"g42",
	"north" : ROOMS+"m16",
	"south" : ROOMS+"g39",
	]) );
}
