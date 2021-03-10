#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"northeast" : ROOMS+"e2430",
	"east" : ROOMS+"e2330",
	]) );
	set_invis_exits(({"northeast","east"}));
}

