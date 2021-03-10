#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g111",
	"east" : ROOMS+"g109",
	"north" : ROOMS+"g75",
	"south" : ROOMS+"g108",
	]) );
}
