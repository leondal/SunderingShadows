#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"southeast" : ROOMS+"e1807",
	"east" : ROOMS+"e1907",
	"north" : ROOMS+"e2006",
	]) );
	set_invis_exits(({"southeast","east","north"}));
}

