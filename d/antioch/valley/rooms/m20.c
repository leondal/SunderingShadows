#include <std.h>
#include "../valley.h"
inherit MEADOW;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m21",
	"east" : ROOMS+"m19",
	"north" : ROOMS+"m22",
	"south" : ROOMS+"m10",
	]) );
}
