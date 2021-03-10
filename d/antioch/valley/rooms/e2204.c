#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"north" : ROOMS+"e2304",
	"east" : ROOMS+"e2205",
	]) );
	set_invis_exits(({"north","east"}));
}

