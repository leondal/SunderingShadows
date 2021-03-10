#include <std.h>
#include "../valley.h"
inherit MEADOW;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m13",
	"east" : ROOMS+"m15",
	"north" : ROOMS+"m18",
	"south" : ROOMS+"m5",
	]) );
}
