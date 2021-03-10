#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"southwest" : ROOMS+"e2203",
	"east" : ROOMS+"v34",
	"west" : ROOMS+"e2303",
	"south" : ROOMS+"e2204",
	]) );
	set_invis_exits(({"southwest","east","west","south"}));
}

