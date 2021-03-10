#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v75",
	"northwest" : ROOMS+"e2729",
	"east" : ROOMS+"e2631",
	]) );
	set_invis_exits(({"northwest","west","east"}));
}

