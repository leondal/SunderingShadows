#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"north" : ROOMS+"cave1",
	"east" : ROOMS+"e2804",
	"southeast" : ROOMS+"e2704",
	]) );
	set_invis_exits(({"north","east","southeast"}));
}

