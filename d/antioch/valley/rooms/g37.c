#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m4",
	"east" : ROOMS+"g36",
	"north" : ROOMS+"m5",
	"south" : ROOMS+"g33",
	]) );
}
