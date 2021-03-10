#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g20",
	"east" : ROOMS+"g18",
	"north" : ROOMS+"g28",
	"south" : ROOMS+"g4",
	]) );
}
