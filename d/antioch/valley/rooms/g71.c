#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g70",
	"east" : ROOMS+"g72",
	"north" : ROOMS+"g64",
	"south" : ROOMS+"g73",
	]) );
}
