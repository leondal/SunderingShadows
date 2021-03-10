#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v79",
	"east" : ROOMS+"e2430",
	"southwest" : ROOMS+"v80",
	"northeast" : ROOMS+"v77",
	"north" : ROOMS+"v76",
	]) );
	set_invis_exits(({"east"}));
}
