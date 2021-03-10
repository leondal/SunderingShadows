#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
	::create();
	set_exits( ([
	"northeast" : ROOMS+"v82",
	"southwest" : ROOMS+"v86",
	"west" : ROOMS+"v85",
	"east" : ROOMS+"e2127",
	"north" : ROOMS+"v83",
	]) );
	set_invis_exits(({"east"}));
}
