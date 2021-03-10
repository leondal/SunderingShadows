#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v31",
	"east" : ROOMS+"g94",
	"north" : ROOMS+"g91",
	"south" : ROOMS+"v29",
	]) );
}
