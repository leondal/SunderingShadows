#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m28",
	"east" : ROOMS+"g54",
	"north" : ROOMS+"g57",
	"south" : ROOMS+"m27",
	]) );
}
