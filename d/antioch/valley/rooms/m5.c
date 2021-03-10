#include <std.h>
#include "../valley.h"
inherit MEADOW1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m6",
	"east" : ROOMS+"g38",
	"north" : ROOMS+"m14",
	"south" : ROOMS+"g37",
	]) );
}
