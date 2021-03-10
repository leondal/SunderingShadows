#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"southeast" : ROOMS+"e2707",
	"east" : ROOMS+"v51",
	"west" : ROOMS+"e2805",
	"north" : ROOMS+"e2906",
	]) );
	set_invis_exits(({"southeast","east","west","north"}));
}

