#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"e1622",
	"south" : ROOMS+"e1523",
	]) );
	set_invis_exits(({"west","south"}));
}
