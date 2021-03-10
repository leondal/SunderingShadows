#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"e2402",
	"east" : ROOMS+"v36",
	]) );
	set_invis_exits(({"west","east"}));
}

