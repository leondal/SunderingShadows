#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g23",
	"east" : ROOMS+"g25",
	"north" : ROOMS+"g119",
	"south" : ROOMS+"g22",
	]) );
}
