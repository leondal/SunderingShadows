#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"e2302",
	"east" : ROOMS+"e2304",
	]) );
	set_invis_exits(({"west","east"}));
}

