#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"e1825",
	"south" : ROOMS+"e1726",
	"north" : ROOMS+"e1926",
	]) );
	set_invis_exits(({"south","west","north"}));
}
