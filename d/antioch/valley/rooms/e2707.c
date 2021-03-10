#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"northwest" : ROOMS+"e2806",
	"south" : ROOMS+"v42",
	]) );
	set_invis_exits(({"northwest","south"}));
}

