#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"northeast" : ROOMS+"e2104",
	"southeast" : ROOMS+"e1904",
	]) );
	set_invis_exits(({"northeast","southeast"}));
}

