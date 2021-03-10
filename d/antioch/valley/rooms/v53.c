#include <std.h>
#include "../valley.h"
inherit VAL_2;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v52",
	"east" : ROOMS+"g67",
	"north" : ROOMS+"v54",
	"south" : ROOMS+"g68",
	"northwest" : ROOMS+"shore10",
	]) );
}
