#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g4",
	"east" : ROOMS+"g6",
	"north" : ROOMS+"g18",
	"south" : ROOMS+"v17",
	]) );
}

