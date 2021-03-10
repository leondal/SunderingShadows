#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"southwest" : ROOMS+"e2104",
	"east" : ROOMS+"v32",
	"west" : ROOMS+"e2204",
	]) );
	set_invis_exits(({"southwest","east","west"}));
}

