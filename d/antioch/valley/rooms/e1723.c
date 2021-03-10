#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v11",
	"east" : ROOMS+"e1724",
	]) );
	set_invis_exits(({"east","west"}));
}
