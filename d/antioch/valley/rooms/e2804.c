#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"e2803",
	"east" : ROOMS+"e2805",
	]) );
	set_invis_exits(({"west","east"}));
}

