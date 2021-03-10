#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"northwest" : ROOMS+"e2007",
	"east" : ROOMS+"v26",
	]) );
	set_invis_exits(({"northwest","east"}));
}

