#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
	::create();
	set_exits( ([
	"northeast" : ROOMS+"v39",
	"southeast" : ROOMS+"v36",
	"east" : ROOMS+"v37",
	"west" : ROOMS+"e2502",
	]) );
	set_invis_exits(({"west"}));
}
