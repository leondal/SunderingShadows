#include <std.h>
#include "../valley.h"
inherit MEADOW;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m14",
	"east" : ROOMS+"g43",
	"north" : ROOMS+"m17",
	"south" : ROOMS+"g38",
	]) );
}
