#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"northeast" : ROOMS+"e2127",
	"east" : ROOMS+"e2027",
	]) );
	set_invis_exits(({"northeast","east"}));
}

