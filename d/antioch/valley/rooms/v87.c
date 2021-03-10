#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
	::create();
	set_exits( ([
	"east" : ROOMS+"v86",
	"west" : ROOMS+"g34",
	"north" : ROOMS+"g35",
	"south" : ROOMS+"v88",
	]) );
}
