#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g9",
	"east" : ROOMS+"g11",
	"north" : ROOMS+"g13",
	"south" : ROOMS+"v12",
	]) );
}
