#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
	::create();
	set_exits( ([
	"northeast" : ROOMS+"v86",
	"southwest" : ROOMS+"v90",
	"west" : ROOMS+"v89",
	"north" : ROOMS+"v87",
	"southeast" : ROOMS+"e1825",
	]) );
	set_invis_exits(({"southeast"}));
}
