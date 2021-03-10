#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g3",
	"east" : ROOMS+"g5",
	"north" : ROOMS+"g19",
	"south" : ROOMS+"v18",
	]) );
}
