#include <std.h>
#include "../valley.h"
inherit VALLEY1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v45",
	"east" : ROOMS+"v47",
	"south" : ROOMS+"g80",
	"north" : ROOMS+"shore6",
	]) );
}
