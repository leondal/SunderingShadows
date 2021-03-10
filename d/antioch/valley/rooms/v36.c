#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
	::create();
	set_exits( ([
	"east" : ROOMS+"v35",
	"north" : ROOMS+"v37",
	"southeast" : ROOMS+"v34",
	"northwest" : ROOMS+"v38",	
	"west" : ROOMS+"e2403",
	]) );
	set_invis_exits(({"west"}));
}
