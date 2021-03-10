#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g66",
	"east" : ROOMS+"v62",
	"north" : ROOMS+"v58",
	"south" : ROOMS+"g64",
	]) );
}
