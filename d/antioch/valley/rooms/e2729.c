#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v73",
	"southeast" : ROOMS+"e2630",
	]) );
	set_listen("default",
	"You can hear the rushing of a river in the distance.",
	);
	set_invis_exits(({"southeast","west"}));
}

