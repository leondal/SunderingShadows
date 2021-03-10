#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"e2026",
	"east" : ROOMS+"e2028",
	"southwest" : ROOMS+"e1926",
	]) );
	set_invis_exits(({"east","west","southwest"}));
}

