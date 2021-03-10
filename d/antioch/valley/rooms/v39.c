#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
	::create();
	set_exits( ([
	"east" : ROOMS+"v40",
	"south" : ROOMS+"v37",
	"west" : ROOMS+"e2603",
	"southwest" : ROOMS+"v38",
	]) );
	set_invis_exits(({"west"}));
}
