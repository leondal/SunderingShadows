#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"northwest" : ROOMS+"e2803",
	"southeast" : ROOMS+"v40",
	"west" : ROOMS+"e2703",
	]) );
	set_invis_exits(({"northwest","southeast","west"}));
}

