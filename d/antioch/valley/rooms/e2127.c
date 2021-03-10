#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v84",
	"southwest" : ROOMS+"e2026",
	]) );
	set_invis_exits(({"southwest","west"}));
}

