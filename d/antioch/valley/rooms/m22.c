#include <std.h>
#include "../valley.h"
inherit MEADOW;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g109",
	"east" : ROOMS+"m23",
	"north" : ROOMS+"g73",
	"south" : ROOMS+"m20",
	]) );
}
