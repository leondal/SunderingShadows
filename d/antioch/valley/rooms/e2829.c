#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v72",
	"east" : ROOMS+"e2830",
	]) );
	set_listen("default",
	"The raging of a river can be heard from nearby.",
	);
	set_invis_exits(({"east","west"}));
}

