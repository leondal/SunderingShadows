#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g75",
	"east" : ROOMS+"g73",
	"north" : ROOMS+"g70",
	"south" : ROOMS+"g109",
	]) );
}
