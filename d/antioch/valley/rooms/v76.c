#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g47",
	"east" : ROOMS+"v77",
	"north" : ROOMS+"v75",
	"south" : ROOMS+"v78",
	]) );
}
