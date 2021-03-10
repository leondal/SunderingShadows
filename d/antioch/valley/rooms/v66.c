#include <std.h>
#include "../valley.h"
inherit VALLEY1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v65",
	"east" : ROOMS+"v67",
	"north" : ROOMS+"rb10",
	"south" : ROOMS+"g56",
	]) );
}
