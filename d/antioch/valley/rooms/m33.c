#include <std.h>
#include "../valley.h"
inherit MEADOW;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g72",
	"east" : ROOMS+"m34",
	"north" : ROOMS+"g62",
	"south" : ROOMS+"m31",
	]) );
}
