#include <std.h>
#include "../valley.h"
inherit GRASS1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g56",
	"east" : ROOMS+"g58",
	"north" : ROOMS+"v67",
	"south" : ROOMS+"g55",
	]) );
}
