#include <std.h>
#include "../valley.h"
inherit VALLEY1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v47",
	"east" : ROOMS+"v49",
	"north" : ROOMS+"shore8",
	"south" : ROOMS+"g78",
	]) );
}
