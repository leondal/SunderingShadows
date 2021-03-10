#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"southeast" : ROOMS+"e1611",
	"east" : ROOMS+"v22",
	"west" : ROOMS+"e1709",
	]) );
	set_invis_exits(({"southeast","east","west"}));
}

