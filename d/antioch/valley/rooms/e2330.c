#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"south" : ROOMS+"e2230",
	"west" : ROOMS+"e2329",
	]) );
	set_invis_exits(({"west","south"}));
}

