#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"east" : ROOMS+"e1928",
	]) );
	set_invis_exits(({"east"}));
}
