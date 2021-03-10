#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"northwest" : ROOMS+"e1710",
	"east" : ROOMS+"v1",
	"south" : ROOMS+"e1511",
	]) );
	set_invis_exits(({"northwest","east","south"}));
}

