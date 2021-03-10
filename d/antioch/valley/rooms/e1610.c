#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"northwest" : ROOMS+"e1709",
	"south" : ROOMS+"e1510",
	]) );
	set_invis_exits(({"northwest","south"}));
}

