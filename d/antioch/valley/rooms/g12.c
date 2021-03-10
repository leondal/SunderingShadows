#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g13",
	"east" : ROOMS+"v89",
	"north" : ROOMS+"g33",
	"south" : ROOMS+"g11",
	]) );
}
