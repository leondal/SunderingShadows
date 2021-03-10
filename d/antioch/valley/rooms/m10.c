#include <std.h>
#include "../valley.h"
inherit MEADOW1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g103",
	"east" : ROOMS+"m11",
	"north" : ROOMS+"m20",
	"south" : ROOMS+"g102",
	]) );
}
