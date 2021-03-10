#include <std.h>
#include "../valley.h"
inherit VALLEY1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g65",
	"east" : ROOMS+"v63",
	"north" : ROOMS+"v59",
	"south" : ROOMS+"g63",
	"northeast" : ROOMS+"rb6",
	]) );
}
