#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g19",
	"east" : ROOMS+"g17",
	"north" : ROOMS+"g29",
	"south" : ROOMS+"g5",
	]) );
}
