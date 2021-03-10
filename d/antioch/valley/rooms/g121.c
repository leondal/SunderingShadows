#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v29",
	"east" : ROOMS+"g120",
	"north" : ROOMS+"g94",
	"south" : ROOMS+"v27",
	]) );
}
