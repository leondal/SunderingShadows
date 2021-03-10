#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"southeast" : ROOMS+"e2006",
	"east" : ROOMS+"e2106",
	"west" : ROOMS+"e2104",
	]) );
	set_invis_exits(({"southeast","east","west"}));
}

