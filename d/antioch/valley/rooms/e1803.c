#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"northeast" : ROOMS+"e1904",
	"southeast" : ROOMS+"e1704",
	]) );
	set_invis_exits(({"northeast","southeast"}));
}

