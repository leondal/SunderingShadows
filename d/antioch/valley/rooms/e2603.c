#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"northwest" : ROOMS+"e2702",
	"east" : ROOMS+"v39",
	]) );
	set_invis_exits(({"northwest","east"}));
}

