#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"e1807",
	"east" : ROOMS+"e1809",
	"south" : ROOMS+"e1708",
	]) );
	set_invis_exits(({"west","south","east"}));
}

