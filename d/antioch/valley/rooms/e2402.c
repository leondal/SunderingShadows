#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"e2401",
	"east" : ROOMS+"e2403",
	"south" : ROOMS+"e2302",
	]) );
	set_invis_exits(({"south","east","west"}));
}

