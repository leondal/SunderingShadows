#include <std.h>
#include "../valley.h"
inherit MEADOW;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g108",
	"east" : ROOMS+"m20",
	"north" : ROOMS+"g109",
	"south" : ROOMS+"g103",
	]) );
}
