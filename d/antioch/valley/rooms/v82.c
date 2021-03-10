#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v83",
	"east" : ROOMS+"e2228",
	"north" : ROOMS+"v81",
	"northeast" : ROOMS+"v80",
	"southwest" : ROOMS+"v84",
	]) );
	set_invis_exits(({"east"}));
}
