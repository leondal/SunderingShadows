#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v90",
	"south" : ROOMS+"e1724",
	"southeast" : ROOMS+"e1725",
	]) );
	set_invis_exits(({"south","west","southeast"}));
}
