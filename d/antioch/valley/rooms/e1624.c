#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"northeast" : ROOMS+"e1725",
	"south" : ROOMS+"e1524",
	]) );
	set_invis_exits(({"northeast","south"}));
}
