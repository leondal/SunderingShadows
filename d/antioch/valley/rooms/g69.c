#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g68",
	"east" : ROOMS+"g70",
	"north" : ROOMS+"g67",
	"south" : ROOMS+"g75",
	]) );
}
