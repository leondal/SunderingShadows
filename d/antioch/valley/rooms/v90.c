#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g11",
	"northeast" : ROOMS+"v88",
	"north" : ROOMS+"v89",
	"southwest" : ROOMS+"v11",
	"east" : ROOMS+"e1824",
	]) );
	set_invis_exits(({"east"}));
}
