#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"e2705",
	"south" : ROOMS+"v41",
	]) );
	set_invis_exits(({"south","west"}));
}

