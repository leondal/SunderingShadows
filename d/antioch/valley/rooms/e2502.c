#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"northwest" : ROOMS+"e2601",
	"east" : ROOMS+"v38",
	]) );
	set_invis_exits(({"northwest","east"}));
}

