#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g27",
	"east" : ROOMS+"g29",
	"north" : ROOMS+"g116",
	"south" : ROOMS+"g19",
	]) );
}
