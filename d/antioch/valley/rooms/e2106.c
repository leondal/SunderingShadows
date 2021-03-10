#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"e2105",
	"east" : ROOMS+"v30",
	]) );
	set_invis_exits(({"west","east"}));
}

