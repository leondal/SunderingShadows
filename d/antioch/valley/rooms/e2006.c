#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"northwest" : ROOMS+"e2105",
	"east" : ROOMS+"e2007",
	"south" : ROOMS+"e1906",
	]) );
	set_invis_exits(({"northwest","east","south"}));
}

