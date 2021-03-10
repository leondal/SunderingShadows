#include <std.h>
#include "../valley.h"
inherit MEADOW1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g73",
	"east" : ROOMS+"m31",
	"north" : ROOMS+"g72",
	"south" : ROOMS+"m23",
	]) );
}
