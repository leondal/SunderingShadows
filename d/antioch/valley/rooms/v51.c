#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
	::create();
	set_exits( ([
	"east" : ROOMS+"v50",
	"west" : ROOMS+"e2806",
	"north" : ROOMS+"shore16",
	"southeast" : ROOMS+"v44",
	]) );
	set_invis_exits(({"west"}));
}
