#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"e2532",
	"south" : ROOMS+"e2433",
	]) );
	set_invis_exits(({"south","west"}));
}

