#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
	::create();
	set_exits( ([
	"east" : ROOMS+"v84",
	"west" : ROOMS+"g35",
	"north" : ROOMS+"g40",
	"south" : ROOMS+"v86",
	]) );
}
