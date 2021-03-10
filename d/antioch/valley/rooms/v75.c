#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v74",
	"east" : ROOMS+"e2630",
	"northwest" : ROOMS+"v73",
	"south" : ROOMS+"v76",
	"southeast" : ROOMS+"v77",
	]) );
	set_invis_exits(({"east"}));
}
