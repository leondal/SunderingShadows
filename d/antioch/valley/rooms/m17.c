#include <std.h>
#include "../valley.h"
inherit MEADOW;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m18",
	"east" : ROOMS+"m16",
	"north" : ROOMS+"m27",
	"south" : ROOMS+"m15",
	]) );
}
