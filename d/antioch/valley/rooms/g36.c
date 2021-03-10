#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g37",
	"east" : ROOMS+"g35",
	"north" : ROOMS+"g38",
	"south" : ROOMS+"g34",
	]) );
}
