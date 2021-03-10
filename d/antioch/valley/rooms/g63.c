#include <std.h>
#include "../valley.h"
inherit GRASS1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g64",
	"east" : ROOMS+"g62",
	"north" : ROOMS+"v62",
	"south" : ROOMS+"g72",
	]) );
}
