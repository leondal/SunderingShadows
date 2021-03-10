#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g1",
	"east" : ROOMS+"g3",
	"north" : ROOMS+"g21",
	"south" : ROOMS+"v20",
	]) );
}
