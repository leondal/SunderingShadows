#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"e1808",
	"east" : ROOMS+"v24",
	]) );
	set_invis_exits(({"west","east"}));
}

